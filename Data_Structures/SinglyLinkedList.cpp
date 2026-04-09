#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};


void Insert(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    else{ 
        Insert(root->next, val);
    }
};

void PrintLL(Node* root){
    if(root == NULL){ return; }
    else{
        while(root != nullptr){
            cout << root->data << " -> ";
            root = root->next;
        }
    }
};

int main(){
    
    Node *root = NULL;
    Insert(root, 4);
    Insert(root, 7);
    Insert(root, 1);
    Insert(root, 9);
    Insert(root, 6);
    PrintLL(root);

}