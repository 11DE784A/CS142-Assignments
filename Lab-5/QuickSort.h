using namespace std;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


class QuickSort {
	public:
	void sort(int unsortedMonstrosity[], int start, int end);
	int* sort(int unsortedMonstrosity[], int length);
	void sort(SLList badStuff, int start, int end);
	SLList sort(SLList badStuff);
};

void QuickSort::sort(int unsortedMonstrosity[], int start, int end) {
	if (end <= 1)
		return;

	int x = unsortedMonstrosity[start + rand()%end];
	int p=start-1, j=start, q=start+end;

	while (j < q) {
		if (unsortedMonstrosity[j] < x) {
			swap(unsortedMonstrosity, j++, ++p);
		} else if (unsortedMonstrosity[j] > x) {
			swap(unsortedMonstrosity, j, --q);
		} else {
			j++;
		}
	}

	sort(unsortedMonstrosity, start, p-start+1);
	sort(unsortedMonstrosity, q, end-(q-start));
}

int* QuickSort::sort(int unsortedMonstrosity[], int length) {
	int* sortedMasterpiece = new int[length];
	for (int i=0; i<length; ++i) {
		sortedMasterpiece[i] = unsortedMonstrosity[i];
	}

	sort(sortedMasterpiece, 0, length);

	return sortedMasterpiece;
}

void QuickSort::sort(SLList badStuff, int start, int end) {
	if (end <= 1)
		return;

	int x = badStuff.get(start + rand()%end + 1);
	int p = start-1, j=start, q=start+end;

	while (j < q) {
		if (badStuff.get(j+1) < x) {
			badStuff.swap((j++)+1, 1+(++p));
		} else if (badStuff.get(j+1) > x) {
			badStuff.swap(j+1, 1+(--q));
		} else {
			++j;
		}
	}

	sort(badStuff, start, p-start+1);
	sort(badStuff, q, end-(q-start));
}

SLList QuickSort::sort(SLList badStuff) {
	SLList goodStuff;
	for (int i=1; i<=badStuff.countItems(); ++i) {
		goodStuff.insert(badStuff.get(i));
	}

	sort(goodStuff, 0, goodStuff.countItems());

	return goodStuff;
}
