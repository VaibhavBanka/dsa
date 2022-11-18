#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
};

Node push(Node* head,int val){
    Node* newnode=new Node();
    newnode->data=val;
    Node* temp=head;
    newnode->next=temp;
}

Node* trav(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        push(head,a);
    }
    trav(head);
}