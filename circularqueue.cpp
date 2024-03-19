#include <iostream>
using namespace std;

class Queue{
    int cqueue[10], front = -1, back = -1, n = 10;

public:
    void enqueue(int data){
        if((front==0 && back==n-1)||(front==back+1)){
            cout<<"queue full"<<endl;
            return;
        }
        if(front==-1){
            front++;
            back++;
        }
        else{
           if(back==n-1){
            back=0;
           }
           else{
            back++;
           }
        }
        cqueue[back]=data;
    }

    void dequeue(){
        if(front==-1){
            cout<<"queue empty"<<endl;
            return;
        }
        if(front==back){
            front=-1;
            back=-1;
        }
        else{
            if(front==n-1){
                front=0;
            }
            else{
                front++;
            }

        }
    }

    void display(){
    int f=front, r = back;
    if (f <= r) {
      while (f <= r){
         cout<<cqueue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<cqueue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<cqueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
        }


};

int main(){
    Queue Q;
    Q.enqueue(4);
    Q.enqueue(7);
    Q.enqueue(4);
    Q.display();
    Q.dequeue();
    Q.display();

}
