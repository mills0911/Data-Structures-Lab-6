//MaxHeap.h
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Tnode.h"

class MaxHeap
{
private:
  Tnode** arr;
  int capacity;
  int size;

  void heapifyUp(int index);
  void heapifyDown(int index);

public:
    MaxHeap(int cap=100);
    ~MaxHeap();

    void insert(Tnode* node);
    Tnode* extractMax();
    bool isEmpty() const;
}
