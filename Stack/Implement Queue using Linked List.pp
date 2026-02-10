

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

class Queue{
public:
    int size;
    Node* start;
    Node* end;

    //constructor
    Queue(){
        start = NULL;
        end= NULL;
        size = 0;
    }

    void push(int n){
        Node* temp = new Node(n);
       if(start == NULL){
         start = end = temp;
       }
       else{
        end->next = temp;
        end=temp;
       }
       size++;
    }

    int pop(){
       if(start == NULL){
        cout<<"stack underflow";
        return -1;
       }
     
       Node* temp = start;
       int removed = temp->data;
       start=start->next;
       delete temp;
       size--;

       if (start == NULL) {
            end = NULL;
        }

        return removed;
    }

    int peek(){
        if(start == NULL){
        cout<<"stack underflow";
        return -1;
       }else{
         return start->data;
       }
    }

  
};

int main(){
   Queue q;

   q.push(10);
   q.push(20);
   q.push(30);

   cout << q.peek() << endl;

   q.pop();
   cout << q.peek() << endl;
}
