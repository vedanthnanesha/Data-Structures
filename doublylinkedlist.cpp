#include <iostream>
using namespace std;

template <typename T>
class Node{

    public:

      T data;
      Node* next;
      Node* prev;

      Node(T val){
         this->data=val;
         this->next=NULL;
         this->prev=NULL;
      }

};

template <typename T>
class Doublylinkedlist{
      Node<T>* head;
      Node<T>* tail;
        public:

        Doublylinkedlist(){
        head = NULL;
        tail= NULL;
        }


    void insertfront(T data){
        Node<T>* newnode = new Node<T>(data);

        newnode->next=head;
        if (head==NULL){
            tail=newnode;
        }

         if (head!=NULL){
            head->prev=newnode;
        }
            head=newnode;

     }

     void insertback(T data){
       Node<T>* newnode = new Node<T>(data);
       if (head==NULL){
        newnode->next=head;
        head=newnode;
        tail=newnode;
        return;
       }

       tail->next=newnode;
       newnode->prev=tail;
       tail=newnode;
     }

     void insertatk(T data, int k){
     Node<T>* newnode = new Node<T>(data);
     if (k==0){
        insertfront(data);
        return;
     }



     Node<T>* temp = head;
     for(int i = 0; i < k-1 ; i++){
        temp=temp->next;
     }
     newnode->next=temp->next;
     newnode->prev=temp;
     temp->next=newnode;
     newnode->next->prev=newnode;
     }

     void deletefront(){
     Node<T>* temp = head;
     head=head->next;
     temp = NULL;

     }

     void deleteback(){
     Node<T>* temp = head;
     if (temp->next==NULL){
        head=NULL;
        return;
     }
     while (temp->next!=NULL){
        temp=temp->next;
     }
     temp->prev->next=NULL;

     }

     void deleteatk(int k){
     if (k==0){
        deletefront();
        return;
     }

     Node<T>* temp = head;
     for(int i = 0; i <= k-1 ; i++){
        temp=temp->next;
     }
     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
     delete temp;

     }

     bool search(int key){
       Node<T>* temp=head;

       while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
       }
       return false;


     }

     void reverse(){
       Node<T>* current = head;
       Node<T>* temp;


       while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
       }
       if(temp!=NULL){
        head=temp->prev;
       }
     }





     void display(){
            Node<T>* temp;
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
   Doublylinkedlist<int> L;

   L.insertback(9);
   L.insertfront(8);
   L.reverse();
   L.display();
   L.reverse();
   L.insertfront(7);
   L.insertfront(1);
   L.display();
   L.insertback(10);
   L.display();
   L.insertatk(69,3);
   L.display();
   L.deleteatk(3);
   L.display();
   L.reverse();
   L.display();
   L.search(1)? cout<<"\nYes" : cout<<"\nNo";
   cout<<"\n"<<L.search(42);


   return 0;
}
