#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
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
void reverse(){
    if(head==NULL) {cout<<"Empty list";return;}
    Node* temp1 =head;
    Node* after = NULL;
    Node* pre = NULL;
    if(temp1->next==NULL) {cout<<"Single node in list";return;}
    while(temp1 != NULL){
        after=temp1->next; //to keep account id address of next term
        temp1->next=pre; //updn in value of address
        pre=temp1; //updn for loop
        temp1=after; //updn for loop
    }
    head=pre;
    
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
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    reverse();
    display();
    return 0;
}
