#include <iostream>
#define MAX_ELEMENT 100

using namespace std;

class Heap
{
private:
    int heap[MAX_ELEMENT];
    int heapSize;

public:
    Heap() : heapSize(0) {}
    void push(int item);
    int pop();
    void printHeap() const;
    int getHeapSize() const;
};

void Heap::push(int item)
{
    if (heapSize == MAX_ELEMENT)
    {
        // 좆된거임
    }
    int i = ++heapSize;

    while ((i != 1) && (item > heap[i / 2]))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

int Heap::pop()
{
    if (heapSize == 0)
    {
        // 좆된거임
    }
    int parent = 1;
    int child = 2;
    int rootnode = heap[1];
    int temp = heap[heapSize--];

    while ((child <= heapSize))
    {
        if (heap[child] < heap[child + 1])
        {
            child++;
        }
        if (temp > heap[child])
        {
            break;
        }
        heap[parent] = heap[child]; // parent 자리에 child가 올라옴 ->child자리는 빈자리
        parent = child;             // 위에 결과에 따라서 빈자리를 parent로 바꿔줌
        child *= 2;                 // 따라서 child도 parent밑으로 오게 2배해줌
    }

    heap[parent] = temp;
    return rootnode;
}

void Heap::printHeap() const
{
    cout << "Heap" << endl;
    for (int i = 1; i < heapSize; i++)
    {
        cout << "[" << heap[i] << "]";
    }
    cout << endl;
}

int Heap::getHeapSize() const
{
    return heapSize;
}

int main()
{
    Heap heap;

    heap.push(10);
    heap.push(45);
    heap.push(19);
    heap.push(11);
    heap.push(96);

    heap.printHeap();
    int n = heap.getHeapSize();

    for (int i = 0; i < n; i++)
    {
        int item = heap.pop();
        cout << "delete : [" << item << "]" << endl;
    }

    return 0;
}