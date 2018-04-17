/*
 * Ayush Singh <ayush.singh@niser.ac.in>
 * Custom array class.
 * Keeps track of number of elements
 * Allows resizing.
 */

#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class Array {
	private:
		T* a;
		int length;

	public:
		Array() {
			length = 0;
			a = NULL;
		}

		Array(int l) {
			length = l;
			a = new T[length];

			for (int i=0; i<length; ++i)
				a[i] = T(NULL);
		}

		T& operator[](int i) {
			assert(0 <= i && i < length);
			return a[i];
		}

		Array<T> operator=(Array<T> arr) {
			if (this == &arr)
				return *this;

			delete [] a;
			length = arr.length;

			if (arr.a) {
				a = new T[arr.length];
				for (int i=0; i<length; ++i)
					a[i] = arr.a[i];
			} else {
				a = NULL;
			}

			return *this;
		}

		int len() {
			return length;
		}

		void resize(int n) {
			if (n + 1 > length) {
				Array<T> b(max(1, 2*n));
				for (int i=0; i<n; ++i)
					b[i] = (*this)[i];

				*this = b;
			}
		}

		void swap(int i, int j) {
			T temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		void print() {
			for (int i=0; i<len(); ++i) {
				cout << a[i] << "\t";
			}
			cout << endl;
		}
};
