#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
};

Node* Insert(Node* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(root -> data >= data){
        root -> left = Insert(root -> left, data);
    }
    else{
        root -> right = Insert(root -> right, data);
    }
    return root;
};

bool Search(Node* root, int data){
    if(root = NULL) return false;
    else if(root -> data == data) return true;
    else if(data <= root -> data) return Search(root -> left, data);
    else return Search(root -> right, data);
};

void Inorder(Node* root){
    if(root == NULL) return;
    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
};

void Preorder(Node* root){
    if(root == NULL) return;
    cout << root -> data << " ";
    Inorder(root -> left);
    Inorder(root -> right);
};

void Postorder(Node* root){
    if(root == NULL) return;
    Inorder(root -> left);
    Inorder(root -> right);
    cout << root -> data << " ";
};

Node* FindMin(Node* root){
    if(root == NULL) return NULL;
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
};

Node* Delete(Node* root, int data){
    if(root == NULL) return root;
    else if(data < root -> data) root -> left = Delete(root -> left, data);
    else if(data > root -> data) root -> right = Delete(root -> right, data);
    else{
        //case 1 : No child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            root = NULL;
        }
        //case 2 : One child
        else if(root -> left == NULL){
            Node* temp = root;
            root = root -> right;
            delete temp;
        }
        else if(root -> right == NULL){
            Node* temp = root;
            root = root -> left;
            delete temp;
        }
        //case 3 : Two children
        else{
            Node *temp = FindMin(root -> right);
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp -> data);
        }
    }
    return root;
};

int main(){

    Node* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    Inorder(root);
    cout << endl;
    Delete(root, 15);
    Inorder(root);
    cout << endl;

    return 0;
}