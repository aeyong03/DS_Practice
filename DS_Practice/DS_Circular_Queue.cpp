#include <iostream>
#include <algorithm> // copy 함수 사용

using namespace std;

class Element
{
    friend class Circular_Queue;

public:
    int key;
};

class Circular_Queue
{
private:
    int capacity;
    Element *queue;
    int rear;
    int front;

public:
    Circular_Queue() : capacity(2), rear(0), front(0)
    {
        queue = new Element[capacity];
    }

    ~Circular_Queue()
    {
        delete[] queue;
    }

    void queueFull();
    void queueEmpty();
    void addQueue(Element item);
    Element deleteQueue();
};

void Circular_Queue::queueFull()
{
    if ((rear + 1) % capacity == front)
    {
        cout << "Queue is full!" << endl;
        cout << "용량 " << capacity << "만큼 증가" << endl;

        int newcapacity = 2 * capacity;
        Element *newqueue = new Element[newcapacity];

        // front + 1부터 rear까지의 요소들을 새 배열로 순서대로 복사
        int start = (front + 1) % capacity;
        if (start < 2 && rear >= start)
        {
            copy(queue + start, queue + start + (capacity - 1), newqueue);
        }
        else
        {
            // 원형 큐 내에서 데이터가 두 부분으로 쪼개져 회전해 있는 경우
            copy(queue + start, queue + capacity, newqueue);
            copy(queue, queue + rear + 1, newqueue + (capacity - start));
        }

        // 기존 배열 메모리 해제 및 새 배열 포인터 연결
        delete[] queue;
        queue = newqueue;

        front = newcapacity - 1;
        rear = capacity - 2;
        capacity = newcapacity;
    }
}

void Circular_Queue::queueEmpty()
{
    if (rear == front)
    {
        cout << "Queue is Empty!" << endl;
    }
}

void Circular_Queue::addQueue(Element item)
{
    if ((rear + 1) % capacity == front)
    {
        queueFull();
    }
    rear = (rear + 1) % capacity;

    // 전달받은 데이터를 배열에 보관
    queue[rear] = item;

    cout << item.key << " 삽입 완료 (rear: " << rear << ", capacity: " << capacity << ")" << endl;
}

Element Circular_Queue::deleteQueue()
{
    if (rear == front)
    {
        queueEmpty();
        return Element{-1};
    }
    front = (front + 1) % capacity;

    cout << queue[front].key << " 삭제 완료 (front: " << front << ")" << endl;
    return queue[front];
}

int main()
{
    Circular_Queue q;
    Element item;

    q.queueEmpty();

    item.key = 1;
    q.addQueue(item);
    item.key = 2;
    q.addQueue(item); // 이 시점에 자동으로 queueFull() 실행되어 용량 확장됨
    item.key = 3;
    q.addQueue(item);
    item.key = 4;
    q.addQueue(item);

    cout << "--- 삭제 연산 시작 ---" << endl;
    q.deleteQueue(); // 1 삭제
    q.deleteQueue(); // 2 삭제
    q.deleteQueue(); // 3 삭제
    q.deleteQueue(); // 4 삭제

    return 0;
}