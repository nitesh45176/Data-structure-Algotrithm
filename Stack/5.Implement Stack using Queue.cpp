

#include<iostream>
#include <queue>
using namespace std;


class Stack{
    
    queue<int> q;
public:
   

    void push(int n){
       int s = q.size();
       q.push(n);

       for(int i=0; i<s; i++){
          q.push(q.front());
          q.pop();
       }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack underflow\n";
            return;
        }
        q.pop();
    }

    // TOP (O(1))
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

   
  
};

int main(){
   Stack pt;

   pt.push(10);
   pt.push(20);
   pt.push(30);

   cout << pt.top() << endl;

   pt.pop();
   cout << pt.top() << endl;
}
