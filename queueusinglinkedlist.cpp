#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};

class Queue{
    Node* front;
    Node* back;
    public:
      Queue(){
          front=NULL;
          back=NULL;
      }


    void enqueue(int data){
        Node* newnode = new Node(data);
        if(back==NULL){
            newnode->next=front;
            front=newnode;
            back=newnode;
            return;
        }
        Node* temp = back;
        temp->next=newnode;
        back=newnode;
    }

    void dequeue(){
        if(back==NULL){
            cout<<"\noops,your list is already empty"<<endl;
            return;
        }

        else if(front->next!=NULL){
        Node* temp=front;
        front=front->next;
        temp=NULL;
        return;
        }
        else{
            front=NULL;
            back=NULL;
        }

    }

    bool isempty(){
        return (back==NULL);
    }



    void display(){
        cout<<"\n";
        if(back==NULL){
            cout<<"Your list is empty"<<endl;
            return;
        }
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<"-->";
            }
        }
    }
};

int main(){
    Queue Q;
    Q.display();
    Q.enqueue(78);
    Q.enqueue(89);
    Q.enqueue(100);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.dequeue();
    Q.display();
    return 0;

}
