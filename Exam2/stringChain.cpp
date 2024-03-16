#include <iostream>
#include <list>

using namespace std;


class Hash{

    private:
        int bucket;
        list<string> *table;
        int stringHash;

    public:
        Hash(int);
        void insert(string, int, int);
        bool search(string, int, int);
        void del(string, int, int);
        int mod(string, int, int);
        void displayHash();
    
};

Hash::Hash(int bkt){

    this -> bucket = bkt;
    table = new list<string>[bucket];

}

int Hash::mod(string word, int initialV, int HashMulti){
   
    stringHash = initialV;

    for(int i = 0; i < word.length(); i++){
        stringHash = (stringHash * HashMulti) + word[i];
    }

    return stringHash % bucket;

}

void Hash::insert(string key, int IV, int HM){

    int index = mod(key, IV, HM);
    list <string> :: iterator i;

    //Flag to check if number already exists
    bool exists = true;
    for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key){
            exists = false;
        }
    }
    
    if (exists){
        table[index].push_back(key);
    }
}

void Hash::del(string key, int IV, int HM){

    int index = mod(key,IV,HM);
    
    list <string> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key){
            break;
        }
    }
    if (i != table[index].end()){
        table[index].remove(key);
    }

}

bool Hash:: search(string key, int IV, int HM){

    int index = mod(key,IV,HM);

    list <string> :: iterator i;
    bool flag = false;

    for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key){
            flag = true; 
        }
    }

    return flag;

}

void Hash:: displayHash(){

    for (int i = 0; i < bucket; i++) {
        cout << i;
        for (auto x : table[i]){
            cout << " --> " << x;
        }
    cout << endl;
    }
    
}



int main()
{
    int size;
    int option;
    string word;
    int initalV = 0;
    int HashMulti = 0;
    cout << "What is the size of the Hash table you would like?" << endl;
    cin >> size;
    Hash h(size);

    cout << "Enter an initial value" << endl;
    cin >> initalV;
    cout << "Enter Hash Multiplier" << endl;
    cin >> HashMulti;

    do{
        cout << "Please enter what you would like to perform" << endl;
        cout << "Press 0 to exit, press 1 to insert, press 2 to delete, press 3 for search, press 4 to display" << endl;
        cin >> option;

        if (option == 1){
            cout << "Enter word you would like to add: " << endl;
            cin >> word;
            h.insert(word, initalV, HashMulti);
        }

        else if (option == 2){
            cout << "Enter word you would like to delete" << endl;
            cin >> word;
            h.del(word, initalV, HashMulti);
        }

        else if (option == 3){
            cout << "Enter word you would like to search" << endl;
            cin >> word;
            if(h.search(word, initalV, HashMulti)){
                cout << "Key has been found! " << endl;
            }
            else{
                cout << "Key does not exist" << endl;
            }
        }

        else if (option == 4){
            h.displayHash();
        }

        else if (option < 0 || option > 4){

            cout << "Invalid option" << endl;
            continue;
        }

    }while(option != 0);

    return 0;
}
