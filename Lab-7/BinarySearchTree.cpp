/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 9 Assignment: Binary Search Tree implementation
 */

#include<iostream>
using namespace std;

template<class T>
class BinarySearchTree {
	/*
	 * All the important stuff happens here.
	 */

	class Node {
		/*
		 * Contains a data storage unit and 
		 * links to its children and parent
		 */

		public:
			T data;
			Node* parent;
			Node* right;
			Node* left;
	
			Node() {
				data = T(NULL);
				parent = right = left = NULL;
			}
	};

	// A pointer to the root node identifies the tree
	Node* root;

	// Private member functions to do the shady stuff...
	
	/* List of private methods:
	 * 	bool findEQ(T key, Node* u);
	 * 	Node* findLast(T key);
	 * 	void display(Node* u);
	 * 	bool addChild(Node* u, Node* p);
	 */

	bool findEQ(T key, Node* u) {
		/*
		 * Recursive function to check if the BST
		 * contains a Node with data value key.
		 * Returns true if such a Node is found,
		 * returns false otherwise.
		 */

		if (u == NULL) {
			return false;
		}

		if (u->data == key) {
			return true;
		} else if (u->data > key) {
			findEQ(key, u->left);
		} else {
			findEQ(key, u->right);
		}
	}

	Node* findLast(T key) {
		/*
		 * Function to find a Node in the BST
		 * to which a new Node with data key could
		 * be added.
		 * Returns the address of the said Node, if found.
		 * Returns NULL if a Node with data key already exists.
		 */

		Node* u = root;
		Node* prev = NULL;

		while (u != NULL) {
			prev = u;
			if (u->data < key) {
				u = u->right;
			} else if (u->data > key) {
				u = u->left;
			} else {
				return u;
			}
		}

		return prev;
	}

	void display(Node* u) {
		/*
		 * Recursive function to display all the elements of the 
		 * tree in ascending order.
		 */

		if (u == NULL) {
			return;
		}

		display(u->left);
		cout << u->data << endl;
		display(u->right);
	}
	
	bool addChild(Node* u, Node* p) {
		/*
		 * Function to add u as a left or right child to p.
		 * Has no checks built in, whatsoever.
		 * Use at your own risk.
		 */

		if (p == NULL) {
			p = u;
		} else {
			if (u->data > p->data) {
				p->right = u;
			} else if (u->data < p->data) {
				p->left = u;
			} else {
				return false;
			}
			u->parent = p;
		}

		return true;
	}
			
	public:
		BinarySearchTree() {
			root = NULL;
		}

		/*
		 * List of methods:
		 * 	bool find(T key);
		 * 	int insert(T data);
		 * 	void display();
		 * 	int delete(T data);
		 */

		Node* find(T key) {
			/* 
			 * Returns true if key is found in the tree,
			 * returns false otherwise.
			 */

			return findLast(key);
		}

		bool insert(T data) {
			/*
			 * Inserts a node with data into the tree.
			 * Returns true if a node is successfully added,
			 * returns false otherwise.
			 */

			Node* p = findLast(data);
			Node* u = new Node;
			u->data = data;

			return addChild(u, p);
		}

		void display() {
			/*
			 * Displays all data elements of the tree in ascending order.
			 */

			display(root);
		}

};

int main() {
	BinarySearchTree<int> bst;
	for (int i=0; i<15; ++i) {
		bst.insert(i);
	}

	cout << bst.find(1) << endl;

	return 0;
}
