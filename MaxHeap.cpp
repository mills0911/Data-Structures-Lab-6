#include "MaxHeap.h"

MaxHeap::MaxHeap(int cap) :capacity(cap), size(0) 
{
	arr = new Tnode * [capacity];
}

MaxHeap::~MaxHeap()
{
	delete[] arr;
}

bool MaxHeap::isEmpty() const
{
	return size == 0;
}

int MaxHeap::getSize() const
{
	return size;
}

//This is so that the higher ratings would come first and any tie breaker is done by frequency

static bool isHigherPriority(Tnode* a, Tnode* b)
{
	if (a->rating != b->rating)
		{
		return a->rating > b->rating;
		}
	return a->frequency > b->frequency;
}

void MaxHeap::heapifyUp(int index)
{
	while (index > 0)
	{
		int parent = (index - 1) / 2;
		if (isHigherPriority(arr[index], arr[parent]))
		{
			Tnode* temp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = temp;
			index = parent;
		}
		else
		{
			break;
		}
	}
}

void MaxHeap::heapifyDown(int index)
{
	while (2 * index + 1 < size)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int largest = index;
		
		if (left<size&&isHigherPriority(arr[left],arr[largest]))
		{
			largest = left;
		}
		if (right < size && isHigherPriority(arr[right], arr[largest]))
		{
			largest = right;
		}
		if (largest != index)
		{
			Tnode* temp = arr[index];
			arr[index] = arr[largest];
			arr[largest] = temp;
			index = largest;
		}
		else
		{
			break;
		}
	}
}

void MaxHeap::insert(Tnode* node)
{
	if (size >= capacity) return;
	arr[size] = node;
	heapifyUp(size);
	size++;
}

Tnode* MaxHeap::extractMax()
{
	if (size <= 0) return nullptr;
	Tnode* root = arr[0];
	arr[0] = arr[size - 1];
	size--;
	heapifyDown(0);
	return root;
}
