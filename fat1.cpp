#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* head=NULL;
void insertatend(int d){
    Node* ptr=new Node();
    ptr->data=d;
    ptr->next=NULL;
    if (head==NULL){
        head=ptr;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void print(){
    Node* temp=head;
    if (head==NULL){
        return;
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
void sub(){
    Node* temp1=head;
    Node* temp2=temp1->next;

    while(temp2!=NULL){
        Node* ptr1=new Node();
        if(temp1->data>=temp2->data){
            ptr1->data=(temp1->data)-(temp2->data);
        }
        else{
            ptr1->data=(temp2->data)-(temp1->data);
        }
        ptr1->next=temp2;
        temp1->next=ptr1;
        temp1=temp1->next->next;
        temp2=temp2->next;
    }
}
void mod(){
    Node* pre=head; 
    Node* temp5=pre->next;       
    while(temp5!=NULL){
        if((pre->data)%10==2){
            head=head->next;
            pre=pre->next;
            temp5=temp5->next;
        }
        else if((temp5->data)%10==2 && temp5->next!=NULL){
            pre->next=temp5->next;
            temp5=temp5->next;
        }
        else if((temp5->data)%10==2 && temp5->next==NULL){
            pre->next=NULL;
            break;
        }
        else{
            pre=temp5;
            temp5=temp5->next;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertatend(x);
    }
    print();
    sub();
    cout<<endl;
    print();
    cout<<endl;
    mod();
    print();
    return 0;
}