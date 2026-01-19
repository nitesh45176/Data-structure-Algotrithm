

#include <iostream>
using namespace std;

class Node{
public:
     int data;
     Node* next;
     

     Node(int data){
        this ->data = data;
        this ->next = NULL;
     }
};

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);  //creating New node
    temp ->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);  //creating New node
    tail ->next = temp;
    tail = tail ->next;
}

void print(Node* &head){

    Node* temp = head;
    
    while(temp != NULL){
        cout<< temp ->data << endl;
        temp = temp -> next ;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    // cout<< node1->data<< endl;
    // cout << node1->next << endl;

    
    Node* head = node1; //head pointed to node1
    Node* tail = node1; //node1 pointed to nail
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);
}
