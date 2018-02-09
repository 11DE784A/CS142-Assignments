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
