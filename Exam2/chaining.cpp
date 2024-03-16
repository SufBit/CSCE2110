#include <iostream>
#include <list>

using namespace std;


class Hash{

    private:
        int bucket;
        list<int> *table;

    public:
        Hash(int);
        void insert(int);
        bool search(int);
        void del(int);
        int mod(int);
        void displayHash();
};

Hash::Hash(int bkt){

    this -> bucket = bkt;
    table = new list<int>[bucket];

}

int Hash::mod(int num){

    return num % bucket;
}

void Hash::insert(int key){

    int index = mod(key);
    list <int> :: iterator i;

    //Flag to check if number already exi
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

void Hash::del(int key){

    int index = mod(key);
    
    list <int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key){
            break;
        }
    }
    if (i != table[index].end()){
        table[index].erase(i);
    }

}

bool Hash:: search(int key){

    int index = mod(key);

    list <int> :: iterator i;
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
    int num;
    cout << "What is the size of the Hash table you would like?" << endl;
    cin >> size;
    Hash h(size);

    
    do{
        cout << "Please enter what you would like to perform" << endl;
        cout << "Press 0 to exit, press 1 to insert, press 2 to delete, press 3 for search, press 4 to display" << endl;
        cin >> option;

        if (option == 1){
            cout << "Enter number you would like to add: " << endl;
            cin >> num;
            h.insert(num);
        }

        else if (option == 2){
            cout << "Enter number you would like to delete" << endl;
            cin >> num;
            h.del(num);
        }

        else if (option == 3){
            cout << "Enter number you would like to search" << endl;
            cin >> num;
            if(h.search(num)){
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
