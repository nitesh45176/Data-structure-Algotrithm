

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    int size;
    int *q;
    int currSize;
    int start;
    int end;

    // constructor
    Queue(int size)
    {
        this->size = size;
        q = new int[size];
        currSize = 0;
        start = -1;
        end = -1;
    }

    void push(int element)
    {
        if (currSize == size)
        {
            cout << "Queue Overflow\n";
            return;
        }

        // First element
        if (currSize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % size;
        }
        q[end] = element;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "Queue underflow";
        }

        int el = q[start];
        if (currSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % size;
        }

        currSize--;
        return el;
    }

    int top()
    {
        if (currSize == 0)
        {
            cout << "Empty stack";
        }
        else
        {
            return q[start];
        }
    }

    void display()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty\n";
        }

        int i = start;
        for (int count = 0; count < currSize; count++)
        {
            cout << q[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.top() << endl;

    q.pop();
    cout << q.top() << endl;
}
