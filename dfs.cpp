#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph{
    public:
        int V;
        vector<list<int>> adj;

        Graph(int size){
            adj.resize(size);
            this->V=size;
        }

        void printlist(){
            for(int i=0; i<V; i++){
                cout<<i;
                for(auto j : adj[i]){
                cout<<"-->"<<j;
                }
                cout<<endl;
            }
            cout<<endl;

        }

        void addedge(int v, int w){
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        void BFS(int source){
            vector<bool> visited;
            visited.resize(V, false);

            queue<int> Q;


            Q.push(source);
            visited[source]=true;

            while(!Q.empty()){
                int s = Q.front();
                cout<<s<<" ";
                Q.pop();


                int count = 0;
                for(int i : adj[s]){
                    if(visited[i]==false){
                        visited[i]=true;
                        Q.push(i);
                        count++;

                    }
                }

            }
        }
};

int main(){
    Graph g(6);
    g.addedge(2, 3);
    g.addedge(0,1);
    g.addedge(2,1);
    g.addedge(3,4);
    g.addedge(0,5);
    g.printlist();
    g.BFS(0);
}
