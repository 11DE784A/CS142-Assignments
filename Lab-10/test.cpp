#include<iostream>
#include "Array.h"
using namespace std;

int main() {
	Array<float> foo (5);

	cout << "len " << foo.len() << endl;
	foo.resize();
	cout << "len " << foo.len() << endl;

	return 0;
}
