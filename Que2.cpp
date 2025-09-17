#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
int count=0;
Node*head=NULL;
void insert(int x){
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
void delete_key(int key);
void check(int x){
    if(head==NULL) {cout<<"Empty list";return;}
    Node* temp1 =head;
    if(temp1->next==NULL) {cout<<"Single node in list";return;}
    while(temp1 != NULL){
            if(temp1 ->data==x){
                temp1=temp1->next; //else delete will delete the address of temp1 but check loop still tries to use it
                delete_key(x);
                count++;
            }
            else{ 
                temp1=temp1->next;
            }
            
        }
    }
void delete_key(int key){
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
    pre-> next =temp1->next;
    delete temp1;
}
void display(){
    if (head==NULL){ cout<<"Empty list";return;}
    Node* temp1 =head;
    while(temp1 != NULL){
         cout<<temp1->data<<" ";
         temp1=temp1->next;
    }
    cout<<endl;
}

int main(){
    insert(1);
    insert(2);
    insert(1);
    insert(2);
    insert(1);
    insert(3);
    insert(1);
    cout<<"Original list: "<<endl;
    display();
    check(1);
    cout<<"Key= "<<1<<" Count= "<<count<<endl;
    display();
    return 0;
}
