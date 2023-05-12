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
  int i=pq->size;
  while(i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){ //ya no
    int aux=pq->heapArray[i].priority;
    pq->heapArray[i].priority = pq->heapArray[i]priority;
    pq->heapArray[i].priority = aux;
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* mon = (Heap*) malloc(sizeof(Heap));
  mon->capac=3;
  mon->size=0;
  mon->heapArray= (heapElem*)malloc(sizeof(heapElem)*mon->capac);

   return mon;
}
