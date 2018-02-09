class Array {
/*
 * User defined Array class. Keeps track of number of elements.
 * Possible to resize the array.
 * Also is very cool.
 */
	public:
	int* a;
	int size;		// Keeps track of number of elements in the array.

	Array (int s) {
		size = s;
		a = new int[size];
	}

	Array () {
		size = 1;
		a = new int[size];
	}

	int& operator[](int i) {	// Overloaded [] to index elements of Array
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
};
