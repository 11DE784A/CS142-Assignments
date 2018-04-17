/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 11 Assignment: Heap Sort
 */

#include<iostream>
#include "MaxHeap.h"
using namespace std;

template<class T>
void heapSort(Array<T> A) {
	MaxHeap<T> h(A);
	int n = h.size();
	for (int i=0; i<n; ++i)
		A[i] = h.remove();
}

int main() {
	Array<int> flu (10);
	for (int i=0; i<10; ++i)
		flu[i] = rand()%50;

	flu.print();
	heapSort(flu);
	flu.print();
	return 0;
}
