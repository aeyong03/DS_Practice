#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class ListNode
{
	friend class LinkedList;

private:
	int data;
	ListNode *link;
	ListNode(int data, ListNode *link = nullptr) : data(data), link(link) {}
};

class LinkedList
{
private:
	ListNode *first;

public:
	LinkedList()
	{
		first = nullptr;
	}

	ListNode *createNode(int data)
	{
		return new ListNode(data);
	}
	void insertNode(ListNode *newNode, ListNode *x);		//??? x??? ????
	void deleteNode(ListNode *removeNode, ListNode *trail); // trail ?? ??? ????
	void printList();										// ??? ????? ???
	ListNode *searchNode(int data);							// ???
};

void LinkedList::insertNode(ListNode *newNode, ListNode *x)
{
	if (x == nullptr)
	{
		first = newNode;
		newNode->link = nullptr;
	}
	else
	{
		newNode->link = x->link;
		x->link = newNode;
	}
}

void LinkedList::deleteNode(ListNode *removeNode, ListNode *trail)
{
	if (trail == nullptr)
	{
		first = nullptr;
		delete removeNode;
	}
	else
	{
		trail->link = removeNode->link;
		delete removeNode;
	}
}

void LinkedList::printList()
{
	cout << "The List contains" << endl;

	for (ListNode *curr = first; curr != nullptr; curr = curr->link)
	{
		cout << " " << curr->data;
	}
	cout << endl;
}

ListNode *LinkedList::searchNode(int data)
{
	for (ListNode *curr = first; curr != nullptr; curr = curr->link)
	{
		if (curr->data == data)
		{
			return curr;
		}
	}
	return nullptr;
}

int main()
{
	LinkedList list1;

	ListNode *Node1 = list1.createNode(10);
	list1.insertNode(Node1, nullptr);

	ListNode *Node2 = list1.createNode(20);
	list1.insertNode(Node2, Node1);

	ListNode *Node3 = list1.createNode(30);
	list1.insertNode(Node3, Node2);

	ListNode *Node4 = list1.createNode(40);
	list1.insertNode(Node4, Node3);

	ListNode *Node5 = list1.createNode(50);
	list1.insertNode(Node5, Node4);

	list1.printList();

	list1.searchNode(30);
	list1.searchNode(100);

	list1.deleteNode(Node3, Node2);
	list1.printList();

	cout << "Hi" << "안녕";

	return 0;
}