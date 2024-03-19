#include <bits/stdc++.h>
using namespace std;

class Node{
      public:
        int data;
        Node* next;

        Node(int x){
          this->data = x;
          this->next = NULL;
        }

};
class Stack{
    Node* top;
        public:
            Stack(){
            top=NULL;
            }
         void push(int data){
            Node* temp = new Node(data);
            temp->next = top;
             top = temp;
         }
        bool isEmpty(){
                return top == NULL;
            }

        void pop(){
            Node* temp;
                if (top == NULL) {
                    cout << "Stack Underflow" << endl;
                    return;
                }
                else {
                    cout<<"the popped element is "<<top->data<<endl;
                    temp = top;
                    top = top->next;
                    delete temp;
                }
         }

         void peek(){
            cout<<"The top element is "<<top->data<<"\n";
            return;
         }

        void display(){
            Node* temp;
                if (top == NULL) {
                    cout << "\nStack Underflow";
                    return;
                }
                else {
                    temp = top;
                    while (temp != NULL) {
                    cout << temp->data;
                    temp = temp->next;
                    if (temp != NULL)
                    cout << " --> ";
                    }
                    cout<<"\n";
        }
        }
};

int main(){
   Stack S;
   S.push(1);
   S.push(2);
   S.push(3);
   S.push(4);
   S.display();
   S.pop();
   S.display();
   S.push(5);
   S.display();
   S.peek();
   string result = S.isEmpty() ? "Stack is empty" : "Stack is not empty";
   cout<<result;

   return 0;}
