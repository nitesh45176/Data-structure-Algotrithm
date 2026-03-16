

#include<iostream>
#include<stack>
using namespace std;

class Node{
public:
     int data;
     Node* next;

     //constructor
     Node(int n){
         data=n;
         next=NULL;
     }
};

class Stack{
public:
    Node* top;
    int size;

    //constructor
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int n){
        Node* temp = new Node(n);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop(){
       if(top == NULL){
        cout<<"stack underflow";
        return -1;
       }
     
       Node* temp = top;
       top=top->next;
       delete temp;
       size--;
    }

    int peek(){
        if(top == NULL){
        cout<<"stack underflow";
        return -1;
       }else{
         return top->data;
       }
    }

  
};

int main(){
   Stack pt;

   pt.push(10);
   pt.push(20);
   pt.push(30);

   cout << pt.peek() << endl;

   pt.pop();
   cout << pt.peek() << endl;
}
