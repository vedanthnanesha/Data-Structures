#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS() {
        vector<bool> visited(vertices, false);
        vector<int> discoveryTime(vertices, 0);
        vector<int> finishTime(vertices, 0);
        int time = 0;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited, discoveryTime, finishTime, time);
            }
        }

        cout << "Vertex\tDiscovery Time\tFinish Time\n";
        for (int i = 0; i < vertices; ++i) {
            cout << i << "\t" << discoveryTime[i] << "\t\t" << finishTime[i] << "\n";
        }
    }

private:
    void DFSUtil(int v, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &finishTime, int &time) {
        visited[v] = true;
        discoveryTime[v] = ++time;

        for (int i : adjList[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited, discoveryTime, finishTime, time);
            }
        }

        finishTime[v] = ++time;
    }
};

int main() {
    Graph g(8);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(6,1);


    cout << "DFS Tree and Discovery/Finish Times:\n";
    g.DFS();

    return 0;
}
