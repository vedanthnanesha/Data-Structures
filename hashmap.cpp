#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->next=NULL;
        this->data=data;
    }
};

class hashmap{
private:
    vector<Node*> hashMap;
    int capacity;

public:
    hashmap(int size){
        this->capacity=size;
        for(int i =0; i<size;i++){
            Node* newnode = new Node(-1);
            hashMap.push_back(newnode);
        }
    }

    int hash(int key){
        return key%capacity;
    }

    void insert(int x){
        int index = hash(x);
        if(hashMap[index]->data==-1){
            hashMap[index]->data=x;
        }
        else{
            Node* newnode = new Node(x);
            Node* temp = hashMap[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }

    void remove(int x){
        int index = hash(x);
        if(hashMap[index]->data==-1){
            cout<<"You cannot remove an empty element";
        }
        else if(hashMap[index]->data==x && hashMap[index]->next==NULL){
            hashMap[index]->data=-1;
        }
        else if(hashMap[index]->data==x){
            Node* temp = hashMap[index];
            hashMap[index]=hashMap[index]->next;
            delete temp;
        }
        else{
            Node* temp = hashMap[index];
            while(temp->next!=NULL){
                temp=temp->next;
                if(temp->data==x){
                    break;
                }
            }
            if(temp->data==x && temp->next==NULL){
                Node* temp2 = hashMap[index];
                while(temp2->next!=temp){
                    temp2=temp2->next;
                }
                temp2->next=NULL;
                delete(temp);
            }
            else if(temp->data==x){
                Node* nextnode = temp->next;
                temp->data=nextnode->data;
                temp->next=nextnode->next;
                delete nextnode;
            }
            else{
                cout<<"Element not found";
            }

        }
    }

    bool search(int x){
        int index =hash(x);
        Node* temp = hashMap[index];
        while(temp!=NULL){
            if(temp->data==x){
                return true;
            }
            temp=temp->next;

        }
        return false;
    }

    void display(){
        for(int i=0;i<capacity;i++){
                Node* temp = hashMap[i];
                while(temp->next!=NULL){
                    cout<<temp->data<<"-->";
                    temp=temp->next;
                }
                cout<<temp->data;
                cout<<endl;

    }
    cout<<endl;
    }

};

int main(){
    hashmap H(7);
    H.insert(6);
    H.insert(11);
    H.insert(4);
    H.display();
    H.remove(4);
    H.display();
    H.search(4)? cout<<"Found" : cout<<"Not found";
}
