#include "RadixTree.h"
void RadixTree__::insert(int num) {
	RadixTree__* root = this;
	while (num > 0) {
		RadixTree__* next = num % 2 == 1 ? root->one : root->zero;
		if (next == nullptr) {
			next = new RadixTree__();
		}
		root = next;
	}
	root->isEnd = true;
	return;
}

void RadixTree__::delect(int num) {
	if (this->search(num) == nullptr) {
		return;
	}
	else {
		delete this->search(num);
	}
}

RadixTree__* RadixTree__::search(int num) {
	RadixTree__* root = this;
	while (num > 0) {
		RadixTree__* next = num % 2 == 1 ? root->one : root->zero;
		if (next == nullptr) return nullptr;
		root = next;
	}
	return root;
}