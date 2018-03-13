/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 8 Assignment
 * Reversing the elements of a linked list in O(n) time without
 * recursion, without using any secondary data structures.
 */

#include<iostream>
#include "SLList.h"
using namespace std;

SLList reverse(SLList &list) {
	Node* p = list.head;
	Node* q = p->next;
	Node* r = q->next;
	
	p->next = NULL;
	while(q != list.tail) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}

	q->next = p;

	Node* temp = list.head;
	list.head = list.tail;
	list.tail = temp;

	return list;
}

int main() {
	SLList foo;
	for (int i=0; i<10; ++i)
		foo.insert(rand()%100);

	foo.display();
	reverse(foo).display();
	foo.display();

	return 0;
}

