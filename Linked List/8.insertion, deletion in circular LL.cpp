
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free from node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        //non-empty list
        //assuming that element is present in the list

        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        //element is present -> curr is representing element vala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail){

    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
    }
    
    do{
        cout<< temp->data << " ";
        temp = temp->next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }
    else{
        //Assuming list is not empty
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 Node list
        if(curr == prev){
            tail== NULL;
        }
        // >=2 node list
        else if(tail == curr){
            tail = prev;
        }
        curr ->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 12);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
}
