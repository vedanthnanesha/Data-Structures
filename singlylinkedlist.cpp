#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){

    this->data = val;
    this->next = NULL;
    }
};

class Linkedlist{
    Node* head;
    public:

    Linkedlist(){
    head = NULL;
    }

     void insertatfront(int data){

          Node* temp = new Node(data);
          temp->next=head;
          head=temp;

          }

          void insertatend(int data){
            Node* newnode = new Node(data);
            if(head==NULL){
                head=newnode;
                return;
            }

            Node* gotoend = head;
            while(gotoend->next!=NULL){
                gotoend=gotoend->next;
            }
            gotoend->next=newnode;
        }

        void insertatk(int data,int k){
            Node* newnode = new Node(data);
            Node* temp = head;
            if(k==0){
                insertatfront(data);
                return;
            }
            for(int c=0;c<k-1;c++){
                temp=temp->next;
            }
            newnode->next = temp->next;
            temp->next=newnode;
        }

        void insertsort(int d){
            Node* test1 = head;
            Node* newnode = new Node(d);

            if(test1->data < test1->next->data){


            while(test1->next->data < d){
                test1=test1->next;
            }
            if(test1==head){
                insertatfront(d);
                return;
            }

            newnode->next=test1->next;
            test1->next=newnode;
            }

            else{
                while(test1->next->data > d && test1->next !=NULL){
                test1=test1->next;
            }
            if(test1==head){
                insertatfront(d);
                return;
            }

            newnode->next=test1->next;
            test1->next=newnode;
            }

        }

        void deletestart(){
            Node* temp = head;
            head=head->next;
            delete temp;
        }

        void deleteend(){
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;

        }

        void deleteatk(int k){
            Node* temp = head;
            if(k==0){
                deletestart();
                return;
            }
            for(int i=0;i<k-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }


            void display(){
            Node* temp;
            cout<<"\n";
            if(head==NULL){
                 cout<<"Your list is empty"<<endl;
                 return;

              } else{
                temp = head;
                while(temp!=NULL){
                 cout<<temp->data;
                 temp=temp->next;
                 if(temp!=NULL)
                 cout<<"-->";
                 }

               }
           }


};

int main(){
  Linkedlist L;

  L.insertatfront(5);
  L.insertatfront(10);
  L.insertatfront(15);
  L.insertatk(20,0);
  L.insertsort(13);
  L.display();
  L.deleteend();
  L.display();
  L.deleteatk(2);
  L.insertatend(69);
  L.deletestart();
  L.display();


  return 0;

}
