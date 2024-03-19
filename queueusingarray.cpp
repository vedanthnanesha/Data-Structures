#include <iostream>
#include <string>
using namespace std;

class Queue{
    public:

    int queue[100],n=100,front=-1,back=-1;

    void EQ(int data){
        if(back==n-1){
            cout<<"YOUR QUEUE IS FULL"<<endl;
            return;
        }
        else{
            if (front == - 1){
             front = 0;
            }
            back++;
            queue[back]=data;
            cout<<"element added is "<<queue[back]<<endl;
        }
    }

    void DQ(){
       if(front==-1){
           cout<<"YOUR QUEUE IS ALREADY EMPTY"<<endl;
           return;
       }
       else if(back==0){
        back=-1;
        front=-1;
       }
       else{
           cout<<"element deleted is "<<queue[front]<<endl;
           for(int i = 0;i<back;i++){
               queue[i]=queue[i+1];
       }
       back--;

    }
    }

    bool isempty(){
        return (front == -1);
    }

    bool isfull(){
        return (back == n-1);
    }


    void peek(){
        cout<<"The first element is "<<queue[front]<<endl;
    }

    void display(){
        if(front==-1){
           cout<<"YOUR QUEUE IS ALREADY EMPTY"<<endl;
           return;
        }

        else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= back; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
        }
    }
};

int main(){
    Queue A;
    A.DQ();
    A.EQ(10);
    A.EQ(11);
    A.EQ(12);
    A.EQ(13);
    A.display();
    A.DQ();
    A.display();
    A.peek();




    return 0;
}


