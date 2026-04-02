#include<iostream>
#include<list>
#include<queue>
using namespace std;

struct Node{
    int label;
    list<int> neighbours;

};

struct Graph{
    int n = 11;
    Node *nodes = new Node[n];

    void initializeNodes(){
        for(int i=0; i<n; i++){
            nodes[i].label = i+1;
        }
    }

    void addEdge(int u, int v){
        nodes[u-1].neighbours.push_back(v);
        nodes[v-1].neighbours.push_back(u);
    }
    
    // //directed from lower number to higher number
    // void addEdge(int u, int v){
    //     if(u<v){
    //          nodes[u-1].neighbours.push_back(v);
    //         }
    //     }

    void BFS(){
        queue<int> Q;
        vector<bool> visited(n, false);

        visited[0] = true;
        Q.push(1);
        while(!Q.empty()){
            int curr = Q.front();
            cout << curr << " ";
            Q.pop();

            for(int neighbour : nodes[curr-1].neighbours){
                if(!visited[neighbour-1]){
                    visited[neighbour-1] = true;
                    Q.push(neighbour);
                }
            }
        }
        
    }

    void DFSHelper(int curr_label, vector<bool> &visited){
        cout << curr_label << " ";
        visited[curr_label-1] = true;


        for(int neighbour : nodes[curr_label-1].neighbours){
            if(!visited[neighbour-1]){
                DFSHelper(neighbour, visited);
            }
        }

    }

    void DFS(){
        int startNode = 1;
        vector<bool> visited(n,false);
        DFSHelper(startNode,visited);
        cout << endl;
    }

    void print(){
        for(int i=0; i<n; i++){
            cout << nodes[i].label << " --> ";
            for(auto nd : nodes[i].neighbours){
                cout << nd << " ";
            }
            cout << "\n";
        }
    }

};
int main(){
    Graph *gp = new Graph;
    gp->initializeNodes();
    gp->addEdge(10,1);
    gp->addEdge(1,11);
    gp->addEdge(1,2);
    gp->addEdge(2,3);
    gp->addEdge(3,4);
    gp->addEdge(11,5);
    gp->addEdge(10,7);

    gp->print();
    gp->BFS();
    cout << "\n";
    gp->DFS();

    return 0;
}