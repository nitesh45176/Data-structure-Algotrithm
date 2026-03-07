
#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:

    // PUSH → O(1)
    void push(int n) {
        s1.push(n);
    }

    // POP
    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue underflow\n";
            return;
        }

        // If s2 is empty, transfer all elements
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    // FRONT
    int top() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};
