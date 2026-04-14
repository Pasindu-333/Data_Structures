#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(n + 1, -1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    dist[s] = 0;
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[curr] + 6; // distance = 6
                q.push(neighbor);
            }
        }
    }
    
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        result.push_back(dist[i]);
    }
    return result;
}

int main(){

    int n = 4; // Number of nodes
    int m = 2; // Number of edges
    int s = 1;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3}
    };

    vector<int> result = bfs(n, m, edges, s);

    for (int d : result) {
        cout << d << " ";
    }

    return 0;
}