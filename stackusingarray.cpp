#include <iostream>
using namespace std;

class Stack{
    public:
                int stack[50],n=50,top=-1;

                void push(int data){
                     if (top>=n-1)
                        cout<<"stack is overflowing"<<endl;
                     else{
                        top++;
                        stack[top]=data;
                     }
                }

                void pop(){
                     if (top<=-1)
                        cout<<"stack is underflowing"<<endl;
                     else{
                        cout<<"the popped element is "<<stack[top]<<endl;
                        top--;
                     }
                }
                void peek(){
                      if (top<=-1)
                        cout<<"stack is underflowing"<<endl;
                      else{
                        cout<<"the top element is "<<stack[top]<<endl;
                      }


                }
                bool isempty(){
                   if (top<=-1)
                       return true;
                   else{
                    return false;
                   }
                }

                bool isfull(){
                   if (top>=n-1){
                      return true;
                   }
                   else{
                    return false;
                   }
                }

                void display(){
                     if(top>=0) {
                      cout<<"Stack elements are: \n";
                      for(int i=top; i>=0; i--)
                      cout<<stack[i]<<" ";
                      cout<<endl;
                   } else
                   cout<<"Stack is empty";

            }
};

int main(){
   Stack S;

   string result = S.isempty() ? "Stack is empty" : "stack is not empty";
   cout<<result<<"\n";
   S.push(5);
   S.push(6);
   S.push(7);
   S.push(11);
   S.push(45);
   S.peek();
   S.pop();
   S.display();

   return 0;

}

