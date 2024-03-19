#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Graph{
   int V;
   list<int> *L;

   public:
      Graph(int v){
        V=v;
        L=new list<int>[V];
      }

      void addedge(int i, int j){
         L[i].push_back(j);
      }
      void printgraphlist(){
         for (int a=0;a<V;a++){
           cout<<a<<"-->";
           for (auto elem:L[a]){
             cout<<elem<<",";
           }
           cout<<endl;
        }
       }
};
int main(){
   ifstream myfile("graphread.txt");
      if(!myfile){
         cerr<<"unable to open file";
         return 0;
      }
      int vertices;
      myfile>>vertices;
      Graph g(vertices);
      int v1;
      int v2;
      while(myfile>>v1>>v2){
         g.addedge(v1,v2);
      }
      myfile.close();
      cout<<"Adjacency list form: "<<endl;
      g.printgraphlist();

      return 0;
}



