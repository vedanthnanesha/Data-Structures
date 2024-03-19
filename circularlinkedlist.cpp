#include <iostream>
using namespace std;

class Node{
public:

    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class Circularlist{

public:
    Node* last;
    Circularlist(){
        last=NULL;
    }

    void insertfront(int data){
        Node* newnode=new Node(data);
        if (last==NULL){
            newnode->next=newnode;
            last=newnode;
            return;
        }
        newnode->next=last->next;
        last->next=newnode;
        }

    void insertend(int data){
        Node* newnode=new Node(data);
        if (last==NULL){
            newnode->next=newnode;
            last=newnode;
            return;
        }
        newnode->next=last->next;
        last->next=newnode;
        last=newnode;
        }

    void insertk(int data,int k){
        Node* newnode=new Node(data);
        if(k==0){
            insertfront(data);
            return;
        }
        Node* temp=last->next;
        for(int i=0;i<k-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

    }

    void deletefirst(){
        if(last==NULL){
            cout<<"your list is already empty"<<endl;
            return;
        }
        else if(last->next==last){
            last=NULL;
            return;
        }

        else{
            Node* t=last->next;
            last->next=t->next;
            free(t);

        }

    }

    void deleteend(){
        if(last==NULL){
            cout<<"your list is already empty"<<endl;
            return;
        }
        else if(last->next==last){
            last=NULL;
            return;
        }
        Node* temp=last;
        Node* x = last;
        while(temp->next!=last){
            temp=temp->next;
        }
        temp->next=x->next;
        last=temp;
        delete x;

    }



    void display(){
        Node* first=last->next;
        Node* temp=first;
        if(last==NULL){
            cout<<"list is empty my brother"<<endl;
            return;
        }
        cout<<endl;
        while(temp->next!=first){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<temp->data;
    }

};

int main(){
    Circularlist C;
    C.insertend(9);
    C.insertfront(10);
    C.insertfront(11);
    C.insertk(99,1);

    C.display();
    C.deleteend();
    C.display();
}
