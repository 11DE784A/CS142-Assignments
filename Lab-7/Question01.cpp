/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Merge Sort for an array
 */

#include<iostream>
#include "Array.h"
using namespace std;

void merge(Array &a0, Array &a1, Array &a) {
	long i0=0, i1=0;
	for (long i=0; i<a.length(); ++i) {
		if (i0 == a0.length()) {
			a[i] = a1[i1++];
		} else if (i1 == a1.length()) {
			a[i] = a0[i0++];
		} else if (a0[i0] > a1[i1]) {
			a[i] = a1[i1++];
		} else {
			a[i] = a0[i0++];
		}
	}
}

void MergeSort(Array &a) {
	if (a.length() <= 1)
		return;

	Array a0 (a.length()/2 + 1);
	Array a1 (a.length()/2 + 1);

	for (long i=0; i<a.length()/2; ++i) {
		a0[i] = a[i];
	}

	for (long i=a.length()/2; i<a.length(); ++i) {
		a1[i - (a.length()/2)] = a[i];
	}

	MergeSort(a0);
	MergeSort(a1);
	merge(a0, a1, a);
}

int main() {
	Array a (100);
	for (long i=0; i<100; ++i) {
		a[i] = rand()%100;
	}

	a.print();
	MergeSort(a);
	a.print();
	cout << "done" << endl;

	return 0;
}	
