#include <iostream>

using namespace std;

#define MAX_SIZE 4

struct Element
{
    int key;
};

class Queue
{
private:
    Element queue[MAX_SIZE];
    int rear;
    int front;

public:
    Queue() : rear(-1), front(-1) {}
    void addQueue(Element item);
    Element deleteQueue();
    void isQueueFull();
    void isQueueEmpty();
};

void Queue::addQueue(Element item)
{
    if (rear == MAX_SIZE - 1)
    {
        isQueueFull();
    }
    queue[++rear] = item;
    cout << "Queue에" << queue[rear].key << "추가됨" << endl;
}

Element Queue::deleteQueue()
{
    if (front == -1 && rear == -1)
    {
        isQueueEmpty();
    }
    Element outElement = queue[front];
    for (int i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }
    cout << "Queue에서" << queue[front].key << "제거됨" << endl;
    return outElement;
}

void Queue::isQueueEmpty()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty!\n"
             << endl;
    }
}

void Queue::isQueueFull()
{
    if (rear == MAX_SIZE - 1)
    {
        cout << "Queue is full!" << endl;
    }
}

int main()
{
    Queue q;
    Element item;
    q.isQueueEmpty();

    item.key = 1;
    q.addQueue(item);

    item.key = 2;
    q.addQueue(item);

    item.key = 3;
    q.addQueue(item);

    item.key = 4;
    q.addQueue(item);

    q.isQueueFull();
    return 0;
}
