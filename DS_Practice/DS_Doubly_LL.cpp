#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class DNode {
	friend class Doubly_LinkedList;
private:
	DNode* leftlink;
	DNode* rightlink;
	int data;

	DNode(int data, DNode* leftlink = nullptr, DNode* rightlink = nullptr) :  data(data), leftlink(leftlink), rightlink(rightlink) {}
	
		
};

class Doubly_LinkedList {
private:
	DNode* first;
public:
	DNode* createNode(int data) {
		return new DNode(data);
	}
	void insertNode(DNode* doneNode, DNode* newNode); 
	void deleteNode(DNode* doneNode, DNode* removeNode); 
	void printList();				
	DNode* searchNode(int data);		
};

void Doubly_LinkedList::insertNode(DNode* doneNode, DNode* newNode) {
	if (doneNode == nullptr) {
		first = newNode;
		newNode->leftlink = newNode;
		newNode->rightlink = newNode;
	}
	else if (doneNode->rightlink == doneNode) {
		newNode->leftlink = doneNode;
		newNode->rightlink = doneNode;
		doneNode->rightlink = newNode;
		doneNode->leftlink = newNode;
	}
	else {
		newNode->rightlink = doneNode->rightlink;
		newNode->leftlink = doneNode;
		doneNode->rightlink = newNode;
		newNode->rightlink->leftlink = newNode;
	}
}

void Doubly_LinkedList::deleteNode(DNode* doneNode, DNode* removeNode) {
	if (doneNode == nullptr) {
		removeNode->leftlink = nullptr;
		removeNode->rightlink = nullptr;
		delete removeNode;
	}
	else {
		doneNode->rightlink = removeNode->rightlink;
		removeNode->rightlink->leftlink = doneNode;
		delete removeNode;
	}
}


void Doubly_LinkedList::printList() {
	
	cout << "The Doubly List contain" << endl;
	for (DNode* curr = first; curr != nullptr; curr = curr->rightlink) {
		cout << " " << curr->data;
		if (curr == first->leftlink) {
			break;
		}
	}
	cout << endl;
}

DNode* Doubly_LinkedList::searchNode(int data) {
	for (DNode* curr = first; curr != nullptr; curr = curr->rightlink) {
		if (curr->data == data) {
			return curr;
		}
	}
	return nullptr;
}


int main() {
	Doubly_LinkedList list;

	DNode* node1 = list.createNode(10);
	list.insertNode(nullptr, node1);

	DNode* node2 = list.createNode(20);
	list.insertNode(node1, node2);

	DNode* node3 = list.createNode(30);
	list.insertNode(node2, node3);

	DNode* node4 = list.createNode(40);
	list.insertNode(node3, node4);

	DNode* node5 = list.createNode(50);
	list.insertNode(node4, node5);

	list.printList();

	list.searchNode(30);
	cout << endl;

	list.deleteNode(node2, node3);
	list.printList();



}