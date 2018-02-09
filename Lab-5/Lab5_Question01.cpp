/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 5 Assignment: Bubble Sort and Quick Sort
 */

#include<iostream>
#include "SLList.h"

using namespace std;

class BubbleSort {
	public:
		int* sort(int unsortedMess[], int length);
		SLList sort(SLList unsortedMess);
		
};

int* BubbleSort::sort(int unsortedMess[], int length) {
	int* sortedStuff = new int[length];
	for (int i=0; i<length; ++i) {
		sortedStuff[i] = unsortedMess[i];
	}

	bool flag=true;
	while (flag) {
		flag = false;
		for (int i=0; i<length; ++i) {
			if (sortedStuff[i] > sortedStuff[i+1]) {
				int temp = sortedStuff[i];
				sortedStuff[i] = sortedStuff[i+1];
				sortedStuff[i+1] = temp;
				flag = true;
			}
		}
	}

	return sortedStuff;
}

SLList BubbleSort::sort(SLList unsortedMess) {
	SLList gloriouslySortedLL;
	for (int i=1; i<=unsortedMess.countItems(); ++i) {
		gloriouslySortedLL.insert(unsortedMess.get(i));
	}

	bool flag=true;
	while (flag) {
		flag = false;
		for (int i=1; i<gloriouslySortedLL.countItems(); ++i) {
			if (gloriouslySortedLL.get(i) > gloriouslySortedLL.get(i+1)) {
				gloriouslySortedLL.swap(i, i+1);
				flag = true;
			}
		}
	}


	return gloriouslySortedLL;
}

int main() {
	SLList l1;
	l1.insert(5);
	l1.insert(4);
	l1.insert(1);
	l1.insert(8);
	l1.insert(7);
	l1.insert(0);
	l1.insert(10);
	l1.insert(3);
	l1.insert(9);
	l1.insert(12);

	l1.display();
	l1.swap(1,l1.countItems());
	l1.display();

	BubbleSort foo; (foo.sort(l1)).display();

	return 0;
}
