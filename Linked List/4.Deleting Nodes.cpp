

#include <iostream>
using namespace std;

class Node{
public:
     int data;
     Node* next;
     
     //constructor
     Node(int data){
        this ->data = data;
        this ->next = NULL;
     }

     //destructor
     ~Node(){
        int value = this ->data;
        //memory free
        if(this->next !=NULL){
            delete next;
            this ->next =NULL;
        }
        cout<< "Memory is free from node with data "<<value<<endl;
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
        cout<< temp ->data << " ";
        temp = temp -> next ;
    }
    cout<<endl;
}

void insertAtPosition(Node* &head, Node* &tail, int d , int position){
    
    //insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt= 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //insert at last
    if(temp ->next == NULL){
        insertAtTail(tail, d);
        return;
    }

   //insert in between
    Node* nodeToInsert = new Node(d);   //creating new node for d
    nodeToInsert ->next = temp->next;
    temp ->next = nodeToInsert;
}

void deleteAtPosition(Node* &head, int position){
    if(position == 1){
       Node* temp = head;
       head = head ->next;
       //memory free
       temp->next = NULL;
       delete temp;
    }else{
       //deleting any middle node or free node
       Node* curr = head;
       Node* prev = NULL;
       int cnt = 1;

       while(cnt < position){
         prev = curr;
         curr = curr ->next;

         cnt++;
       }
      prev ->next = curr->next;
      curr->next = NULL;
      delete curr;
    }
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

    insertAtPosition(head, tail, 20, 1);
    print(head);

    deleteAtPosition(head, 3);
    print(head);
}
