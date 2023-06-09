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
  pq->heapArray[0]=pq->heapArray[pq->size-1];
  pq->size--; //???
  if(pq->size==1){
    pq->capac=0;
    return;
  }
  for(int i=0; i< pq->size; i++){ 
    int son=2i+1;
    int son2=2i+2;
    int taita=(i-1)/2;
    if(pq->heapArray[son].priority > pq->heapArray[son2].priority){
      heapElem aux=pq->heapArray[taita];
      pq->heapArray[taita] = pq->heapArray[son];
      pq->heapArray[son] = aux;
    }
    else{
      heapElem aux=pq->heapArray[taita];
      pq->heapArray[taita] = pq->heapArray[son2];
      pq->heapArray[son2] = aux;
    }
  }
}

Heap* createHeap(){
  Heap* mon = (Heap*) malloc(sizeof(Heap));
  mon->capac=3;
  mon->size=0;
  mon->heapArray= (heapElem*)malloc(sizeof(heapElem)*mon->capac);

   return mon;
}
