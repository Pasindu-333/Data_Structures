#include<iostream>
using namespace std;

struct Node{
    string user_name;
    string password;
    Node *link;
};

struct LinkedList{
    Node *head = NULL;
    Node *tail = NULL;

    int length = 0;

    void insert(string user_name, string password){
        if(head == NULL){
            Node *temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            head = temp;

            length++;
        }
        else{
            Node *temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            tail = head;
            while(true){
                if(tail->link == NULL){
                    break;
                }
                else{
                    tail = tail->link;
                }
            }
            tail->link = temp;
        } 
    }

        Node* search(string user_name){
            Node* temp = head;
            while(temp != NULL){
                if(temp->user_name == user_name){
                    return temp;
                }
                temp = temp->link;
            }
            return NULL;
        }
};

struct HashTable{

    static const int MAX_LENGTH = 10;

    LinkedList table[MAX_LENGTH];

    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(char c : user_name){
            sum+=int(c);
        }
        hash = sum % MAX_LENGTH;
        return hash;
    }

    int insert(string user_name, string password){
        int index = hashfunc(user_name);
        table[index].insert(user_name, password);
        return 0;
    }
 
    bool hash_lookup(string user_name){
        int index = hashfunc(user_name);
        Node* result = table[index].search(user_name);
        if(result != NULL){
            cout << result->password << endl;
            return 0;
        }
        return 1;
    }
};

int main(){

    HashTable ht;
    ht.insert("Pasindu", "123");
    ht.insert("Oshan","4353");
    ht.insert("Isuru","999");
    
    cout << ht.hash_lookup("Pasindu")<<endl;
    cout << ht.hash_lookup("Oshan")<<endl;
    cout << ht.hash_lookup("Isuru")<<endl;

    return 0;
}