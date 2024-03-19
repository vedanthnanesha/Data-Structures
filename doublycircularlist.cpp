#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
     this->data=data;
     this->next=NULL;
     this->prev=NULL;
     }
};

class DLCP{
    Node* start;
public:
    DLCP(){
    start=NULL;
    }
void insertEnd(int value){


    if (start == NULL) {
        Node* new_node = new Node(value);
        new_node->next = new_node->prev = new_node;
        start = new_node;
        return;
    }


    Node* last = (start)->prev;


    Node* new_node = new Node(value);
    new_node->next = start;


    (start)->prev = new_node;

    new_node->prev = last;

    last->next = new_node;
}


void insertBegin(int value)
{
    if (start == NULL) {
        Node* new_node = new Node(value);
        new_node->next = new_node->prev = new_node;
        start = new_node;
        return;
    }


    Node* last = (start)->prev;

    Node* new_node = new Node(value);


    new_node->next = start;
    new_node->prev = last;

    last->next = (start)->prev = new_node;


    start = new_node;
}
void deletestart(){
    Node* last=start->prev;
    Node* temp=start;
    last->next=start->next;
    start->next->prev=last;
    start=start->next;
    delete temp;

}
void deleteend(){
    Node* last = start->prev;
    start->prev=last->prev;
    last->prev->next=last->next;
    delete last;

}

void insertAfter(int value1,int value2)
{
    Node* new_node = new Node(value1);



    Node* temp = start;
    while (temp->data != value2)
        temp = temp->next;
    Node* next = temp->next;


    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}

void display()
{
    Node* temp = start;

    cout<<"\nTraversal in forward direction \n";
    while (temp->next != start) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;

    cout<<"\nTraversal in reverse direction \n";
    Node* last = start->prev;
    temp = last;
    while (temp->prev != last) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

};
int main()
{
    DLCP D;

    D.insertBegin(5);


    D.insertBegin(4);


    D.insertEnd(7);


    D.insertEnd(8);


    D.insertAfter(6, 5);
    D.deleteend();

    printf("Created circular doubly linked list is: ");
    D.display();
    D.deletestart();
    D.display();

    return 0;
}
