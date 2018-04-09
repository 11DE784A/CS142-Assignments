#include<iostream>
using namespace std;

class Array {
/*
 * User defined Array class. Keeps track of number of elements.
 * Possible to resize the array.
 * Also, is very cool.
 */
	public:
	long* a;
	long size;		// Keeps track of number of elements in the array.

	Array (long s) {
		size = s;
		a = new long[size];
		for (long i=0; i<size; ++i) {
			a[i] = '\0';
		}
	}

	Array () {
		size = 1;
		a = new long[size];
		for (long i=0; i<size; ++i) {
			a[i] = '\0';
		}
	}

	long& operator[](long i) {	// Overloaded [] to index elements of Array
		return a[i];			// like normal arrays.
	}

	Array& operator=(Array &b) {	// = needs to be overloaded
		if (a != NULL)				// because the class contains a pointer.
			delete [] a;
		a = b.a;
		b.a = NULL;
		size = b.size;
		return *this;
	}

	void print() {
		for (long i=0; i<length(); ++i) {
			cout << a[i] << ", ";
		}

		cout << "NULL" << endl;
	}

	long length() {
		for (long i=0; i<size; ++i) {
			if (a[i] == '\0')
				return i;
		}
	}
};
