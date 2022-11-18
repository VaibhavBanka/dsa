#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int count;
    int level;
    Node* left;
    Node* right;
};
Node* insert(Node* root,int d){
    Node* newn=new Node();
    newn->data=d;
    newn->left=NULL;
    newn->right=NULL;
    newn->count=1;
    if(root==NULL){
        root=newn;
        return newn;
    }
    if(d==root->data){
        (root->count)++;
        return root;
    }
    if(d<root->data)
    root->left=insert(root->left,d);
    else if(d>root->data)
    root->right=insert(root->right,d);
    return root;
}
Node* min(Node* root){
    Node* curr=root;
    while(curr->left!=NULL)
    curr=curr->left;
    return curr;
}
void printl(Node* root1,int i){
    if(root1==NULL)
    return;
    if(i==1)
    cout<<root1->data<<" ";
    else if(i>1){
        printl(root1->left,i-1);
        printl(root1->right,i-1);
    }
}

int height(Node* n){
    if(n==NULL){
        return 0;
    }
    else{
        int lh=height(n->left);
        int rh=height(n->right);
        if(lh>rh){
            return lh+1;
        }
        else
        return rh+1;
    }
}

void level(Node* root){
    int h=height(root);
    for(int i=0;i<=h;i++){
        printl(root,i);
    }
}

void count(Node* root){
    int c1=0,c2=0;
    while((root)!=NULL){
        if((root->count)>c1)
        c1=root->count;
        root=root->left;
    }
    while((root)!=NULL){
        if((root->count)>c2)
        c2=root->count;
        root=root->right;
    }
    if(c1>c2)
        cout<<c1;
    else
        cout<<c2;
}

int main(){
    Node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    Node* mi=min(root);
    cout<<mi->data<<endl;
    level(root);
    cout<<endl;
    count(root);
    return 0;
}