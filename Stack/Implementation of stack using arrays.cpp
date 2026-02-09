

#include<iostream>
#include<stack>
using namespace std;


class Stack{
public:
    int size;
    int *arr;
    int top;

    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    void push(int element){
        if(top < size-1){
            top++;
            arr[top] = element;
        }else{
            cout<<" Stack overflow";
        }
    }

    void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"stack is empty";
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
   Stack st(5);

   st.push(10);
   st.push(20);
   st.push(30);

   cout << st.peek() << endl;

   st.pop();
   cout << st.peek() << endl;
}
