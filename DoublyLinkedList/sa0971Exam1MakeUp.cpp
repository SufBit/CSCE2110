//Sufyan Arshad
//sa0971

#include <iostream>

using namespace std;


//Creating a Node with a data value, next and previous
class Node{

    public:
        int data;
        Node* next;
        Node* prev;    
};

//In order to start the doubly linked list
class LinkList{

    //Creating a node head and tail
    Node* head;
    Node* tail;

    public:

        //declaring empty list, with both head and tail being 0.
        LinkList(){
            head = tail = NULL;
        }

        //Function to insert node.
        void insertNode(int d){
            if (head == NULL){
                //Creating a node
                head = new Node();
                head -> data = d;
                tail = head;
                head -> next = NULL;
                head -> prev = NULL;
            }

            else{
                //Assigning a temporary node to the head node.
                Node * temp = head;
                //Traverse through list if the list is not empty
                while(temp -> next != NULL){
                    temp = temp -> next;
                }

                //Assign value to new node next.
                temp -> next = new Node();
                tail = temp -> next;
                temp -> next -> data = d;
                temp->next->next = NULL;
                temp -> next -> prev = temp;
            }
        }

        //Function to delete node.
        void deleteNode(int d){

            //Start at node head.
            Node* temp = head;

            //Condition to remoove if value found
            if (temp -> data == d){
                head = temp -> next;
                head -> prev = NULL;
                delete(temp);
            }
            else{
                //Traverse throught list until value is found.
                while (temp -> next -> data != d){
                    temp = temp -> next;
                }

                if (temp -> next -> next == NULL){
                    delete(temp -> next);
                    tail = temp;
                    temp -> next = NULL;
                    return;
                }

                Node* aTemp = temp -> next;
                temp -> next = temp -> next -> next;
                temp -> next -> prev = temp;
                delete(aTemp);
                
            }
        }
        
        //Function to sort list.
        void bubbleSort(){

            int swapped, i;
            Node* temp;
            Node* temp2 = NULL;

            //Check if list is not empty.
            if (temp == NULL){
                return;
            }
            do{
                i = 0;
                temp = head;
                //Traverse throught list until not empty.
                while (temp -> next != temp2)
                {
                    if (temp -> data > temp -> next -> data){

                        //Swap list in order to sort
                        swapped = temp -> data;
                        temp -> data = temp ->next -> data;
                        temp -> next -> data = swapped;
                        i = 1;
                    }

                    temp = temp -> next;
                }
                temp2 = temp;
            }while(i != 0);
            
            
        }

        //Search for value in list.
        void search(int d){

            Node* temp = head;
            int pos = 0;

            //Traverse until value is found or a NULL is found.
            while (temp -> data != d && temp -> next != NULL)
            {   
                //In order to see how many times traversed to get position of value
                pos++;

                //Move to next vaue
                temp = temp -> next;
            }

            if (temp -> data != d){
                cout << "Value not present in list" << endl;
            }
            else{
                cout << "Value found at: " << pos + 1 << endl;
            }
        }

        //Function to display
        void display(){

            Node* temp = head;
            if (temp == NULL){
                cout << "Linked list is empty" << endl;
                return;
            }

            else{
                cout << "Your linked list is: " << endl;
                while(temp != NULL){
                    cout << temp -> data << " -> ";
                    temp = temp -> next;
                }
                cout << endl;
            }
        }


};

int main(){

        LinkList obj;
        int choice, value = 0;

        do{

            cout << "Press 1 to insert" << endl;
            cout << "Press 2 to delete" << endl;
            cout << "Press 3 to sort" << endl;
            cout << "Press 4 to search" << endl;
            cout << "Press 5 to display" << endl;
            cout << "Press 0 to end" << endl;
            cin >> choice;

            if (choice == 1){
                cout << "Enter data to insert: " << endl;
                cin >> value;
                obj.insertNode(value);
            }

            if (choice == 2){
                cout << "Enter data to delete: " << endl;
                cin >> value;
                obj.deleteNode(value);
            }

            if (choice == 3){
                obj.bubbleSort();
            }

            if (choice == 4){
                cout << "Enter value you want to search" << endl;
                cin >> value;
                obj.search(value);
            }

            if (choice == 5){
                obj.display();
            }

        }while(choice != 0);
        

}