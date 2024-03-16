#include <iostream>
#include <list>
#include <cmath>
using namespace std;

class Hash{

    private:
        int bucket;
        int emptyFromstart = -1;
        int emptyAfterRemoval;
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

    int R = log2(bucket);
    int squaredKey = num * num;
    int lowBitsToRemove = (32-R)/2;
    int extractedBits = squaredKey >> lowBitsToRemove;
    extractedBits = extractedBits & (0xFFFFFFFF >> (32 - R));
    return extractedBits % bucket;

}

void Hash::insert(int key){

    bool exists = true;
    int index = mod(key);
    cout << index;
    int bktsProbed = 0;
    int N = bucket;

    if (table[index].front() != key){

        while (bktsProbed < N)
        {
            if (table[index].empty()){
                table[index].push_back(key);
                break;
            }

            index = (index + 1) % N;
            ++bktsProbed;
        }
    }

    else{

        cout << "That number already exists" << endl;
    }
}

void Hash:: del(int key){

    int index = mod(key);
    int bktsProbed = 0;
    int N = bucket;

    while ((table[index].front() != emptyFromstart) && (bktsProbed < N))
    {
        if (!(table[index].empty()) && table[index].front() == key){

            table[index].remove(table[index].front());
            emptyAfterRemoval = index;
        }

        else if (table[index].empty()){
            if (index == emptyAfterRemoval){
                emptyFromstart = -1;
            }
            else{
                emptyFromstart = table[index].front();
            }
        } 

        index = (index + 1) % N;
        ++bktsProbed;
    }
    
}

bool Hash:: search(int key){

    int index = mod(key);
    int bktsProbed = 0;
    int N = bucket;
    bool flag = false;

   while (table[index].front() != emptyFromstart && bktsProbed < N )
   {
    if (!(table[index].empty()) && table[index].front() == key){
        emptyAfterRemoval = index;
        flag = true;
    }
    else if (table[index].empty()){
        if (index == emptyAfterRemoval){
            emptyFromstart = -1;
        }
        else{
            emptyFromstart = table[index].front();
        }
    }

    index = (index + 1) % N;
    ++bktsProbed;     
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

int main(){

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
            cout << " Number has been delete, unless an empty bucked was found first" << endl;
        }

        else if (option == 3){
            cout << "Enter number you would like to search" << endl;
            cin >> num;
            if(h.search(num)){
                cout << "Key has been found! " << endl;
            }
            else{
                cout << "Empty bucket from start found before Key!" << endl;
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



