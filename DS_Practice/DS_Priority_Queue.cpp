// 최대 힙을 이용한 오름차순 출력

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class PriorityQueue
{
private:
    int heap[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}

    void enqueue(int item)
    {
        if (size >= MAX_SIZE)
        {
            cerr << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        int i = ++size;
        while (i > 1 && item > heap[i / 2])
        {
            heap[i] = heap[i / 2];
            i /= 2;
        }
        heap[i] = item;
    }

    int dequeue()
    {
        if (size == 0)
        {
            throw out_of_range("Queue is empty. Cannot dequeue.");
        }
        int parent = 1;
        int child = 2;
        int rootNode = heap[1];
        int temp = heap[size--];

        while (child <= size)
        {
            if (heap[child] < heap[child + 1])
            {
                child++;
            }
            if (temp > heap[child])
            {
                break;
            }

            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        return rootNode;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(10);
    pq.enqueue(45);
    pq.enqueue(19);
    pq.enqueue(11);
    pq.enqueue(96);

    cout << "Dequeue elements is decending order : " << endl;

    while (!pq.isEmpty())
    {
        int item = pq.dequeue();
        cout << item << " ";
    }

    return 0;
}