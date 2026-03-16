#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BT{
    public:

    Node* insert(Node* root, int data){
        if(root == NULL){
            return new Node(data);
        }
        else if(data <= root -> data){
            root -> left = insert(root -> left, data);
        }
        else{
            root -> right = insert(root -> right, data);
        }
        return root;
    }

    // root -> left -> right
    void preOrder(Node* root){
        if(root == NULL) return;
        cout << root -> data << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }

    // left -> root -> right
    void inOrder(Node* root){
        if(root == NULL) return;
        inOrder(root -> left);
        cout << root -> data << " ";
        inOrder(root -> right);
    }

    // left -> right -> root
    void postOrder(Node* root){
        if(root == NULL) return;
        postOrder(root -> left);
        postOrder(root -> right);
        cout << root -> data << " ";
    }

    //function to find lowest common ancestor
    Node* findLCA(Node* root, int v1, int v2){
        if(root == NULL) return NULL;

        if(v1 < root -> data && v2 < root -> data){
            return findLCA(root -> left, v1, v2);
        }

        if(v1 > root -> data && v2 > root -> data){
            return findLCA(root -> right, v1, v2);
        }
        return root;
    }

    Node* FindMin(Node* root){
        if(root == NULL) return NULL;

        while(root -> left != NULL){
            root = root -> left;
        }
        return root;
    }

    Node* Delete(Node* root, int data){
        if(root == NULL) return root;
        else if(data < root -> data){
            root -> left = Delete(root -> left, data);
        }
        else if(data > root -> data){
            root -> right = Delete(root -> right, data );
        }
        else{
            //case 1 : No child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                root = NULL;
                return root;
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
            //case 3 : 2 children
            else{
                Node* temp = FindMin(root -> right);
                root -> data = temp -> data;
                root -> right = Delete(root -> right, temp -> data);
            }
        }
        return root;

    }
};


int main(){

    BT binaryTree;
    Node* root = NULL;

    // int arr[] = {2, 6, 21, 3, 1, 11, 34, 4, 1};
    int arr[] = { 4, 2, 3, 1, 7, 6};

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        root = binaryTree.insert(root, arr[i]);
    }

    binaryTree.inOrder(root);
    binaryTree.Delete(root, 4);
    binaryTree.inOrder(root);


    return 0;
}