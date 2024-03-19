#include <bits/stdc++.h>
using namespace std;

#define V 5

int minkey(int key[], bool mstset[]){
    int mins = INT_MAX;
    int min_index;
    for (int v =0; v < V; v++){
        if(mstset[v]==false && key[v]<mins){
            mins = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printmst(int parent[], int graph[V][V]){
    cout<<"Edge \t Weight"<<endl;
    for (int i =1; i<V;i++){
        cout<<parent[i]<<" - "<<i<<" \t";
        cout<<graph[parent[i]][i]<<endl;
    }
}

void primsmst(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mstset[V];

    for(int i = 0; i<V; i++){
        key[i]=INT_MAX;
        mstset[i]= false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count++){
        int u = minkey(key, mstset);
        mstset[u]= true;

        for(int v =0; v<V; v++){
            if(graph[u][v]&& graph[u][v]<key[v]&&mstset[v]==false){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printmst(parent, graph);
}

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },{ 0, 3, 0, 0, 7 },{ 6, 8, 0, 0, 9 },{ 0, 5, 7, 9, 0 } };
    primsmst(graph);
}
