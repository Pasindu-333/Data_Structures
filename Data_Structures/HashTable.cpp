#include<iostream>
using namespace std;

struct HashTable{

    int MAX_LENGTH = 3;
    string *passwords = new string[MAX_LENGTH];

    // HashTable(int MAX_LENGTH){
    //     this->MAX_LENGTH = MAX_LENGTH;
    //     this->passwords = new string[MAX_LENGTH];
    // }

    void initialize_hashtable(){
        for(int i=0; i<MAX_LENGTH; i++){
            passwords[i].clear();
        }
    }

    bool isFull(){
        for(int i=0; i<MAX_LENGTH; i++){
            if(passwords[i].empty()){
                return false;
            }
        }
        return true;
    }

    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(char c : user_name){
            sum+=int(c);
        }
        hash = sum % MAX_LENGTH;
        return hash;
    }

    bool is_slot_empty(int hash){
        bool empty = passwords[hash].empty();
        return empty;
    }

    int insert(string user_name, string user_password){
        int hash = hashfunc(user_name);
        if(is_slot_empty(hash)){
            passwords[hash] = user_password;
            return 0;
        }
        return 1;
    }

    int hash_lookup(string user_name){
        int hash = hashfunc(user_name);
        if(is_slot_empty(hash)){
            return 0;
        }
        cout << passwords[hash] << endl;
        return 1;
    }
};

int main(){

    HashTable *ht = new HashTable();

    ht->initialize_hashtable();
    ht->insert("Pasindu", "1234");
    ht->insert("Karunarathna", "657");
    ht->insert("Isuru","889");
    ht->insert("David","559");
    
    cout << ht->hash_lookup("Pasindu") << endl;
    cout << ht->hash_lookup("Karunarathna") << endl;
    cout << ht->hash_lookup("Isuru") << endl;
    cout << ht->hash_lookup("David") << endl;
    cout << ht->isFull();

    return 0;
}