#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
     public:
         int vertices;
         vector<list<int>> adjlist;


         Graph(int V){
             this->vertices=V;
             adjlist.resize(V);
         }

         void addedge(int v, int u){
             adjlist[v].push_back(u);
         }

         void DFS(int start){
             vector<bool> visited(vertices, false);
             vector<int> discovery(vertices, 0);
             vector<int> finish(vertices, 0);
             int time = 0;

             for(int i = start; i<vertices; i++){
                if(visited[i]==false){
                    DFSCALL(i, visited, discovery, finish, time);
                }

             }
             for(int i = 0; i<start; i++){
                if(visited[i]==false){
                    DFSCALL(i, visited, discovery, finish, time);
                }
             }

            cout << "Vertex\tDiscovery Time\tFinish Time\n";
            for (int i = 0; i < vertices; ++i) {
            cout << i << "\t" << discovery[i] << "\t\t" << finish[i] << "\n";
        }
         }
         void DFSCALL(int v, vector<bool> &visited, vector<int> &discovery, vector<int> &finish, int &time){
             visited[v]=true;
             discovery[v]=++time;
             for (int i : adjlist[v]){

                if(visited[i]==false){
                    DFSCALL(i, visited, discovery, finish, time);
                }
             }
             finish[v]=++time;
         }



         };

int main(){
        Graph g(9);
        g.addedge(0,1);
        g.addedge(1,3);
        g.addedge(1,2);
        g.addedge(1,0);
        g.addedge(6,7);
        g.DFS(6);
}
