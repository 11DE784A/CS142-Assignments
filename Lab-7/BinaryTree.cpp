/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Binary Tree Implementation
 */

#include<iostream>
using namespace std;

class BTNode {
	public:
		BTNode* parent;
		BTNode* right;
		BTNode* left;

		BTNode() {
			parent = right = left = NULL;
		}
};

class BinaryTree {
	private:
		Node* root;

	public:
		int depth(BTNode* u);
		int size(BTNode* u);
		int size();
		int height(BTNode* u);
		void traverse(Node* u);
		void traverse();
		void bfTraverse();
};

int BinaryTree::depth(BTNode* u) {
	if (u == NULL)
		return 0;

	return 1 + depth(u->parent);
}

int BinaryTree::size(BTNode* u) {
	if (u == NULL)
		return 0;

	return 1 + size(u->left) + size(u->right);
}

int BinaryTree::size() {
	BTNode* u = root;
	BTNode* prev = NULL;
	BTNode* next;
	int n=0;

	while (u != NULL) {
		if (prev == u->parent) {
			++n;
			if (u->left != NULL) {
				next = u->left;
			} else if (u->right != NULL) {
				next = u->right;
			} else {
				next = u->parent;
			}
		} else if (prev == u->left) {
			if (u->right != NULL) {
				next = u->right;
			} else {
				next = u->parent;
			}
		} else {
			next = u->parent;
		}

		prev = u;
		u = next;
	}

	return n;
}

int BinaryTree::height(BTNode* u) {
	if (u == NULL)
		return 0;

	return 1 + max(height(u->left), height(u->right));
}

void BinaryTree::traverse(Node* u) {
	if (u == NULL)
		return NULL;

	traverse(u->left);
	traverse(u->right);
}

void BinaryTree::traverse() {
	BTNode* u = root;
	BTNode* prev = NULL;
	BTNode* next;

	while(u != NULL) {
		if (prev == u->parent) {
			if (u->left != NULL) {
				next = u->left;
			} else if (u->right != NULL) {
				next = u->right;
			} else {
				next = u->parent;
			}
		} else if (prev == u->left) {
			if (u->right != NULL) {
				next = u->right;
			} else {
				next = u->parent;
			}
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

void BinaryTree::bfTraverse() {
	// todo
	return;
}

int main() {

	return 0;
}
