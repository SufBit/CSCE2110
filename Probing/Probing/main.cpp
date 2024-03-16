#include <iostream>
#include <list>

using namespace std;

class Hash{

    private:
        int bucket;
        list<int> *table;
        int emptyFromstart = -1;
        int emptyAfterRemoval;
    public:
        Hash(int);
        void insert(int, int, int);
        bool search(int, int, int);
        void del(int, int, int);
        int mod(int);
        void displayHash();
        void setMT(int);
        int getMT();
};

Hash::Hash(int bkt){

    this -> bucket = bkt;
    table = new list<int>[bucket];

}

// void Hash::setMT(int i){
//     emptyAfterRemoval = i;
// }

// int Hash:: getMT(){

//     return emptyAfterRemoval;
// }

int Hash::mod(int num){

    return num % bucket;
}

void Hash::insert(int key, int c1, int c2){
    int i = 0;
    int bktsProbed = 0;
    int N = bucket;

    int index = mod(key);
    while (bktsProbed < bucket)
    {
        if (table[index].empty()){
            table[index].push_back(key);
            break;
        }

        i++;
        index = (mod(key) + c1*i + c2 *i *i) % N;
        bktsProbed = bktsProbed + 1;
    }
    
}

void Hash::del(int key, int c1, int c2){
    int i = 0;
    int bktsProbed = 0;
    int index = mod(key);
    int N = bucket;

    while (table[index].front() != emptyFromstart && bktsProbed < N)
    {
        if ((!(table[index].empty())) && (table[index].front() == key)){
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

        i = i + 1;
        index = (mod(key) + c1*i + c2 *i *i) % N;;
        bktsProbed++;
    }

}

bool Hash::search (int key, int c1, int c2){

    int i = 0;
    int index = mod(key);
    int bktsProbed = 0;
    int N = bucket;
    bool flag = false;

   while (table[index].front() != emptyFromstart && bktsProbed < N )
   {
    if (!(table[index].empty()) && table[index].front() == key){
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

    i = i + 1;
    index = (index + c1*i + c2 *i *i) % N;
    bktsProbed++;

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
    int c1;
    int c2;
    cout << "What is the size of the Hash table you would like?" << endl;
    cin >> size;
    Hash h(size);

    cout << "Enter first constant" << endl;
    cin >> c1;
    cout << "Enter second constant" << endl;
    cin >> c2;
 
    do{
        cout << "Please enter what you would like to perform" << endl;
        cout << "Press 0 to exit, press 1 to insert, press 2 to delete, press 3 for search, press 4 to display" << endl;
        cin >> option;

        if (option == 1){
            cout << "Enter number you would like to add: " << endl;
            cin >> num;
            h.insert(num, c1, c2);
        }

        else if (option == 2){
            cout << "Enter number you would like to delete" << endl;
            cin >> num;
            h.del(num, c1, c2);
            cout << "Item has been deleted, if empty bucket not found firt" << endl;
        }

        else if (option == 3){
            cout << "Enter number you would like to search" << endl;
            cin >> num;
            if(h.search(num, c1, c2)){
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
        }

    }while(option != 0);

    return 0;
}


