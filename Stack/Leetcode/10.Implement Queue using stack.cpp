
// Leetcode  42 : Implement Queue using stack
// Approach : stack
// Tc and SC: O(n)  ,  S(n)

class MyQueue {
private: 
      stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty() && s2.empty()) {
            return -1;
        }

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s1.empty() && s2.empty()) {
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
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
