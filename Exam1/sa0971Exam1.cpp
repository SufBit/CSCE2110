//SufyanArshad 
//Sa0971

//Will be using circular linked list
//Will be using insertion sort

#include <iostream>

using namespace std;

class list{

private:

    struct Node{

        int data;
        Node *next;

    };

    Node* temp;
    Node* head; //Stays at start
    Node* curr; //used to traverse

public:

    list(){

        temp = NULL;
        head = NULL;
        curr = NULL;

    }

    void addNode(int d){

        Node* n = new Node;
        n -> data = d;
        n -> next = NULL;
        if (head != NULL){
            curr = head;
            while (curr -> next != NULL){
                curr = curr -> next; 
            }
            curr -> next = n;
        }
        else{

            head = n;
        }


    }

    void deleteNode(int d){

        Node* delPtr = NULL;
        temp = head;
        curr = head;
        while(curr != NULL && curr -> data != d){
            temp = curr;
            curr = curr -> next;
        }
        if (curr == NULL){
            cout << "data not found in list" << endl;
            delete delPtr;
        }
        else{

            delPtr = curr;
            curr = curr -> next;
            temp -> next = curr;
            if (delPtr == head){
                head = head -> next;
                temp = head;
            }
            delete delPtr;
            cout << delPtr -> data << " Was deleted from list." << endl;

        }
    }

    void print(){

        curr = head;
        while (curr != NULL)
        {
            cout << curr -> data << endl;
            curr = curr -> next;
        }
        
    }

};




int main(){

    int Option, data;
    list l1;

    do{
    cout << "Pick what process you would like to do" << endl;
    cout << "Press 1 to append data into list" << endl;
    cout << "Press 2 to delete node" << endl;
    cout << "Press 3 to print list" << endl;
    cout << "Press 0 to end process" << endl;
    cin >> Option;

        switch(Option)
        {
        case 1:
            cout << "enter data you would like to add: ";
            cin >> data;
            l1.addNode(data);
            break;
        case 2:
            cout << "enter data you would like to delete: ";
            cin >> data;
            l1.deleteNode(data);
            break;
        case 3:
            l1.print();
            break;
        
        default:
            break;
        }
    }while(Option != 0);
    


    return 0;
}