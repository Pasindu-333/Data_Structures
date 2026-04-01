#include<iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> neighbours;

};

struct Graph{
    int n = 8;
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
    gp->addEdge(1,2);
    gp->addEdge(1,3);
    gp->addEdge(1,5);
    gp->addEdge(1,4);
    gp->addEdge(2,3);
    gp->addEdge(2,6);
    gp->addEdge(4,6);
    gp->addEdge(4,7);
    gp->addEdge(4,8);
    gp->addEdge(5,6);
    gp->addEdge(5,7);
    gp->addEdge(5,8);
    gp->print();

    return 0;
}