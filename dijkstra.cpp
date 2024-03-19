#include <bits/stdc++.h>
using namespace std;

#define V 9

int mindistance(int dist[], bool sptset[]){
    int min = INT_MAX;
    int minindex;
    for(int v = 0; v<V; v++){
        if(sptset[v]==false && dist[v]<min){
            minindex = v;
            min = dist[v];
        }
    }
    return minindex;
}

void printspt(int dist[]){
    cout<<"Vertex \t Distance from Source"<<endl;
    for(int i =0; i<V; i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

void dijkstra(int graph[V][V], int source){
    bool sptset[V];
    int dist[V];

    for(int v =0 ; v<V; v++){
        sptset[v]= false;
        dist[v]= INT_MAX;
    }

    dist[source] = 0;

    for(int count =0 ; count < V-1; count++){
        int u = mindistance(dist, sptset);
        sptset[u] = true;

        for(int v =0 ; v<V; v++){
            if(sptset[v]==false && graph[u][v] && dist[u]!= INT_MAX && graph[u][v]+dist[u]<dist[v]){
                dist[v]= dist[u]+graph[u][v];
            }
        }
    }

    printspt(dist);


}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 6);

}
