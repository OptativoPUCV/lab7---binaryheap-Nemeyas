#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size==0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->capac==pq->size){
    pq->capac=pq->capac*2+1;
    pq->heapArray= (heapElem*)realloc(pq->heapArray, pq->capac*sizeof(heapElem));
  }
  int i=pq->size;
  pq->heapArray[i].data=data;
  pq->heapArray[i].priority=priority;
  while(i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){ 
    heapElem aux=pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = pq->heapArray[i];
    pq->heapArray[i] = aux;
    i = (i-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){
  int i=pq->size;
  //ciclo
  int aux=pq->heapArray[(i-1)/2].priority;
      pq->heapArray[(i-1)/2].priority = pq->heapArray[i].priority;
      pq->heapArray[i].priority = aux;
  //fin del ciclo
  pq->size--;
}

Heap* createHeap(){
  Heap* mon = (Heap*) malloc(sizeof(Heap));
  mon->capac=3;
  mon->size=0;
  mon->heapArray= (heapElem*)malloc(sizeof(heapElem)*mon->capac);

   return mon;
}
