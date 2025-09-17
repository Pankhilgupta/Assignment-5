#include <iostream>
using namespace std;
class Node{
    int data;
    Node* next;
};
Node*head=NULL;
void insert_begin(int x){
    Node* temp = new Node;
    temp->data =x;
    temp->next=NULL;
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}
void insert_end(int x){
    Node* temp = new Node;
    temp->data =x;
    temp->next=NULL;
    if(head==NULL) {head=temp;return;}
    Node* temp1 =head;
    while(temp1->next != NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
}
void insert_middle(int x,int key,bool b){
    Node* temp = new Node;
    temp->data =x;
    temp->next=NULL;
    if(head==NULL) {head=temp;return;}
    Node* temp1 =head;
    Node * pre =NULL;
    while(temp1->next != NULL && temp1->data != key){
            pre =temp1;
            temp1=temp1->next;
    }
    if(b==0){ //insert before
        
        if(temp1==head){
            temp->next=head;
            head=temp;
        }
        else if( temp1==NULL){
            cout<<"Value not found";
        }
        else {
            temp->next=pre->next;
            pre->next=temp;
        }
    }
    if(b==1){ //insert after
        if(temp1==head){
            head->next=temp;
        }
        else if(temp1==NULL){
            cout<<"Value not found";
        }
        else {
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
}

void delete_beg(){
    if(head==NULL) {cout<<"Empty list";return;}
    Node* temp1 =head;
    head=temp1->next;
    delete temp1;
}
void delete_end(){
    if(head==NULL) {cout<<"Empty list";return;}
    Node* temp1 =head;
    if(head->next==NULL){ //only one element
        head=NULL;
        delete temp1;
        return;
    }
    Node* pre =NULL;
    while(temp1->next != NULL){
        pre =temp1;
        temp1=temp1->next;
    }
    pre->next =NULL;
    delete temp1;
}
void delete_middle(int key){
    if(head==NULL) {cout<<"List is empty";return;}
    Node* temp1 =head;
    if(head->data == key){
        head = head->next;
        delete temp1;
        return;
    }
    Node * pre =NULL;
    while(temp1 != NULL && temp1->data != key){
            pre =temp1;
            temp1=temp1->next;
    }
    if (temp1 == NULL) { // key not found
        cout << "Key not found";
        return;
    }
    pre-> next =temp1->next;
    delete temp1;
}
void search(int x){
    Node* temp1 =head;
    if (head==NULL){ cout<<"Empty list";return;}
    while(temp1 != NULL){
        if(temp1->data ==x){
            cout<<"Value found";
            return;
        }
        temp1=temp1->next;
    }
    if (temp1 ==NULL) cout<<"Value not found";
}
void display(){
    if (head==NULL){ cout<<"Empty list";return;}
    Node* temp1 =head;
    while(temp1 != NULL){
         cout<<temp1->data<<" ";
         temp1=temp1->next;
    }
}
int main(){
    int choice, val, key;
    bool b;
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a key\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete by key\n";
        cout << "7. Search\n";
        cout << "8. Display\n";

    do{
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insert_begin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insert_end(val);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter key value: ";
                cin >> key;
                cout << "Enter 0 to insert before, 1 to insert after: ";
                cin >> b;
                insert_middle(val, key, b);
                break;

            case 4:
                delete_beg();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                cout << "Enter key to delete: ";
                cin >> key;
                delete_middle(key);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                search(val);
                break;

            case 8:
                display();
                break;
            default:
                cout << "Invalid choice\n";
        }while(choice <9)
    return 0;
    }
