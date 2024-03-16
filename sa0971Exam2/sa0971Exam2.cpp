#include <iostream>
#include <list>
#include <vector>

using namespace std;


//Hash class to take variables and implement respective functions
class Hash{

    private:
        int bucket;
        list<string> *table;
        string emptyFromstart = "-1";
        int emptyAfterRemoval;
        int stringHash;
        
    public:
        Hash(int);
        void insert(string, int, int, int, int);
        bool search(string, int, int, int, int);
        void del(string, int, int, int, int);
        int mod(string, int, int);
        void displayHash();
};

//Stores how large we want the table to be
Hash::Hash(int bkt){

    this -> bucket = bkt;
    table = new list<string>[bucket];

}

//Is the string Multiplicative hash function
int Hash::mod(string word, int initialV, int HashMulti){

    stringHash = initialV;

    for(int i = 0; i < word.length(); i++){
        stringHash = (stringHash * HashMulti) + word[i];
    }

    return stringHash % bucket;
}

//To insert elements into table
void Hash::insert(string key,int IV, int HM,int c1, int c2){
    int i = 0;
    int bktsProbed = 0;
    int N = bucket;

    int index = mod(key, IV, HM);
    while (bktsProbed < bucket)
    {
        if (table[index].empty()){
            table[index].push_back(key);
            break;
        }

        i++;
        index = (mod(key, IV, HM) + c1*i + c2 *i *i) % N;
        bktsProbed = bktsProbed + 1;
    }
    
}

//Delete items from table
void Hash::del(string key, int IV, int HM, int c1, int c2){
    int i = 0;
    int bktsProbed = 0;
    int index = mod(key, IV, HM);
    int N = bucket;

    while (table[index].front() != emptyFromstart && bktsProbed < N)
    {
        if ((!(table[index].empty())) && (table[index].front() == key)){
            table[index].remove(table[index].front());
            emptyFromstart = index;
        }
        //Was to check if bucket was empty or not, but getting malloc error on cell machines:
        else if (table[index].empty()){
            if (index == emptyAfterRemoval){
                emptyFromstart = "-1";
            }
            else{
                emptyFromstart = table[index].front(key);
            }
        }

        i = i + 1;
        index = (mod(key, IV, HM) + c1*i + c2 *i *i) % N;
        bktsProbed++;
    }

}

//Search elements from table
bool Hash::search (string key,int IV, int HM, int c1, int c2){

    int i = 0;
    int index = mod(key, IV, HM);
    int bktsProbed = 0;
    int N = bucket;
    bool flag = false;

   while (table[index].front() != emptyFromstart && bktsProbed < N )
   {
    if (!(table[index].empty()) && table[index].front() == key){
        emptyAfterRemoval = index;
        flag = true;
    }

    //Was to check if bucket was empty or not, but getting malloc error on cell machines:

    else if (table[index].empty()){
        if (index == emptyAfterRemoval){
            emptyFromstart = "-1";
        }
        else{
            emptyFromstart = table[index].front();
        }
    }

    i = i + 1;
    index = (mod(key, IV, HM) + c1*i + c2 *i *i) % N;
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
    string word;
    int c1;
    int c2;
    int initalV = 0;
    int HashMulti = 0;
    cout << "What is the size of the Hash table you would like?" << endl;
    cin >> size;
    Hash h(size);

    cout << "Enter an initial value" << endl;
    cin >> initalV;
    cout << "Enter Hash Multiplier" << endl;
    cin >> HashMulti;

    cout << "Enter first constant" << endl;
    cin >> c1;
    cout << "Enter second constant" << endl;
    cin >> c2;
 
    do{
        cout << "Please enter what you would like to perform" << endl;
        cout << "Press 0 to exit, press 1 to insert, press 2 to delete, press 3 for search, press 4 to display" << endl;
        cin >> option;

        if (option == 1){
            cout << "Enter word you would like to add: " << endl;
            cin >> word;
            h.insert(word, initalV, HashMulti, c1, c2);
        }

        else if (option == 2){
            cout << "Enter word you would like to delete" << endl;
            cin >> word;
            h.del(word, initalV, HashMulti, c1, c2);
            cout << "Item has been deleted, if empty bucket not found first" << endl;
        }

        else if (option == 3){
            cout << "Enter word you would like to search" << endl;
            cin >> word;
            if(h.search(word, initalV, HashMulti, c1, c2)){
                cout << "Word has been found! " << endl;
            }
            else{
                cout << "Word does not exist" << endl;
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
