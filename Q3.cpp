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
void middle(){
    count=0;
    if(head==NULL) {cout<<"Empty list";return;}
    Node* temp1 =head;
    if(temp1->next==NULL) {cout<<"Single node in list";return;}
    while(temp1 != NULL){
        count++;
        temp1=temp1->next;
    }
}
void display(){
    int mid;
    if(count%2 == 0){mid=count/2;}
    else{
        mid=(count+1)/2;
    }
    int n=1;
    Node* temp1 =head;
    while(temp1 !=NULL && n!=mid ){
         temp1=temp1->next;
         n++;
    }
    if(count%2 == 0){
        cout << "Middle node 1: " << temp1->data << endl;
        cout << "Middle node 2: " << temp1->next->data << endl;
    }
    else{
        cout << "Middle node: " << temp1->data << endl;
    }
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    middle();
    display();
    return 0;
}
