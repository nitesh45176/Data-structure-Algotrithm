




#include<iostream>
using namespace std;

class Node{
public:
      int data;
      Node* prev;
      Node* next;

       // Contructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
}
void insertAtHead( Node *&tail,Node *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail=temp;
    }
    else
    {

        Node *temp = new Node(d);

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail,Node *&head, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {

        Node *temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int d, int position)
{

    // insert at start
    if (position == 1)
    {
        insertAtHead(tail,head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        insertAtTail(tail,head, d);
        return;
    }

    // insert in between
    Node *nodeToInsert = new Node(d); // creating new node for d
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(tail,head, 11);
    print(head);

    insertAtHead(tail,head, 8);
    print(head);

    insertAtHead(tail,head, 9);
    print(head);

    insertAtTail(tail,head, 15);
    print(head);

    insertAtPosition(head, tail, 100, 2);
    print(head);

    insertAtPosition(head, tail, 106, 1);
    print(head);

    insertAtPosition(head, tail, 200, 8);
    print(head);

    deleteAtPosition(head, 1);
    print(head);
}
