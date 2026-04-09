#include<iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

struct CompareEdge {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList; 
public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight)); 
    }

    vector<Edge> primMST(int startNode) {
        priority_queue<Edge, vector<Edge>, CompareEdge> pq;
        vector<bool> inMST(V, false);
        vector<Edge> mstEdges;

        // Add starting node to MST
        inMST[startNode] = true;

        // Add all edges connected to starting node to pq
        for (auto neighbor : adjList[startNode]) {
            pq.push(Edge(startNode, neighbor.first, neighbor.second));
        }

        while (!pq.empty()) {
            // Extract the edge with the minimum weight
            Edge currentEdge = pq.top();
            pq.pop();

            int u = currentEdge.dest;

            // If the destination node is already in MST, skip it
            if (inMST[u]) continue;

            // Include node in MST
            inMST[u] = true;
            mstEdges.push_back(currentEdge);

            // Iterate through all adjacent vertices of the newly added node
            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If neighbor is not in MST, add the edge to the priority queue
                if (!inMST[v]) {
                    pq.push(Edge(u, v, weight));
                }
            }
        }
        return mstEdges;
    }
};

int main(){

Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 5, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(4, 5, 4);

    vector<Edge> mst = g.primMST(0);
    for (auto e : mst) {
        cout << "(" << e.src << ", " << e.dest << ") - Weight: " << e.weight << endl;
    }

    return 0;
}