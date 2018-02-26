/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 6 Assignment: Binary Search
 */

#include<iostream>
#include "SLList.h"
#include "Array.h"
using namespace std;

class BinarySearch {
/*
 * BinarySearch class.
 * Searches for an element in an array/linked list in which
 * all elements are arranged in ascending order.
 */

	private:
		int searchArray(Array a, int start, int end, int key);
		int searchLList(SLList l, int start, int end, int key);

	public:
		int searchArray(Array a, int length, int key);
		int searchLList(SLList l, int key);
};

int BinarySearch::searchArray(Array a, int start, int end, int key) {
/*
 * Returns -1 if the key is not found in the array,
 * returns the index of the key-element otherwise.
 */
	if (key > a[end-1] || key < a[start]) {		// Checks if the key is in the array.
		cout << "Search unsuccessful." << endl;
		return -1;
	}

	int p = (start+end)/2;
	if (a[p] == key) {
		return p;
	} else if (a[p] > key) {
		searchArray(a, p, end, key);
	} else {
		searchArray(a, start, p, key);
	}
}

int BinarySearch::searchArray(Array a, int length, int key) {
/*
 * Returns -1 if the key is not found in the array,
 * returns the index of the key-element otherwise.
 */
	return searchArray(a, 0, length, key);
}

int BinarySearch::searchLList(SLList l, int start, int end, int key) {
/*
 * Returns -1 if the key is not found in the linked list.
 * Returns the index of the key otherwise.
 */
	if (key > l.get(end) || key < l.get(start)) { // Checks if the key is in the LL.
		cout << "Search unsuccessful." << endl;
		return -1;
	}

	int p = (start+end)/2;
	if (l.get(p) == key) {
		return p;
	} else if (l.get(p) > key) {
		searchLList(l, p, end, key);
	} else {
		searchLList(l, start, p, key);
	}
}

int BinarySearch::searchLList(SLList l, int key) {
/*
 * Returns -1 if the key is not found in the linked list.
 * Returns the index of the key otherwise.
 */
	return searchLList(l, 1, l.countItems(), key);
}

int main() {

	return 0;
}
