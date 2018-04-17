/*
 * Ayush Singh (1711037)
 * Programming and Data Sructures Laboratory II (2018)
 * MaxHeap implementation.
 */

#include<iostream>
#include "Array.h"
using namespace std;

template<class T>
class MaxHeap {
	private:
		Array<T> a;
		int n=0;

		int left(int i) {
			return 2*i + 1;
		}

		int right(int i) {
			return 2*i + 2;
		}

		int parent(int i) {
			return (i-1)/2;
		}

	public:
		MaxHeap(Array<T> b) {
			a = b;
			n = b.len();
			for (int i = n/2-1; i >= 0; --i)
				heapify(i);
		}

		int size() {
			return n;
		}

		bool add(T x) {
			a.resize(n);

			a[n++] = x;
			bubbleUp(n-1);
			return true;
		}

		void bubbleUp(int i) {
			int p = parent(i);
			while (i > 0 && a[p] < a[i]) {
				a.swap(i, p);
				i = p;
				p = parent(i);
			}
		}

		T remove() {
			T x = a[0];
			a[0] = a[--n];
			heapify(0);
			a.resize(n);
			return x;
		}

		void heapify(int i) {
			do {
				int j = -1;
				int r = right(i);
				int l = left(i);

				if (r < n && a[r] > a[i]) {
					if (a[r] > a[l]) {
						j = r;
					} else {
						j = l;
					}
				} else {
					if (l < n && a[l] > a[i]) {
						j = l;
					}
				}

				if (j >= 0)
					a.swap(i, j);

				i = j;
			} while (i >= 0);
		}

		void print() {
			for (int i=0; i<n; ++i)
				cout << a[i] << "  ";

			cout << endl;
		}
};
