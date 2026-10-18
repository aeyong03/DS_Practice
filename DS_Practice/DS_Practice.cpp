#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class ListNode
{
public:
	int data;
	ListNode *link;
	ListNode(int data, ListNode *link = nullptr) : data(data), link(link) {}
};

// 새로운 노드 생성
ListNode *createNode(int data, ListNode *link = nullptr)
{
	ListNode *newNode = new ListNode(data, link);
	if (!newNode)
	{										// newNode == nullptr
		cout << "메모리 할당 에러" << endl; // cout 대신 cerr을 쓰는데 이건 또 뭐임?
		exit(1);							// exit가 뭐임
	}
	return newNode;
}

// 새로운 노드를 헤더에 삽입
void insertHead(ListNode **first, ListNode *newNode)
{ // first는 왜 더블포인터?
	newNode->link = *first;
	*first = newNode;
}

// 새로운 노드를 x의 뒤에 삽입
void insert(ListNode **first, ListNode *x, ListNode *newNode)
{
	if (*first)
	{ // 이게 뭐임?
		newNode->link = x->link;
		x->link = newNode;
	}

	else
	{
		newNode->link = nullptr;
		*first = newNode;
	}
}

// 리스트로부터 노드를 삭제, trail은 삭제될 removeNode의 선행노드이며 first는 리스트의 시작
void deleteNode(ListNode **first, ListNode *trail, ListNode *removeNode)
{
	if (trail)
	{ // 뭔데이게
		trail->link = removeNode->link;
	}
	else
	{
		*first = (*first)->link;
	}
	delete removeNode;
}

// 리스트의 출력
void printList(ListNode *first)
{
	cout << "The list contains : ";
	for (; first; first = first->link) // 뭐야이건
	{
		cout << " " << first->data;
	}
	cout << endl;
}

// 탐색
ListNode *search(ListNode *first, int x)
{
	for (; first; first = first->link)
	{
		if (first->data == x)
		{
			return first;
		}
	}
	return nullptr;
}

int main()
{
	ListNode *list = nullptr;
	ListNode *temp = nullptr;

	insertHead(&list, createNode(10));
	insertHead(&list, createNode(20));
	insertHead(&list, createNode(30));
	insertHead(&list, createNode(40));
	insertHead(&list, createNode(50));

	temp = search(list, 30);

	insert(&list, temp, createNode(25));
	printList(list);

	deleteNode(&list, temp, temp->link);

	deleteNode(&list, nullptr, list);
	printList(list);

	return 0;
}