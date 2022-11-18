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

void inorder(Node* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"("<<root->count<<")"<<" ";
    inorder(root->right);
}
Node* min(Node* root){
    Node* curr=root;
    while(curr->left!=NULL)
    curr=curr->left;
    return curr;
}
Node* max(Node* root){
    Node* curr=root;
    while(curr->right!=NULL)
    curr=curr->right;
    return curr;
}

Node* deletenode(Node* root,int d){
    if (root==NULL) return root;
    if(d<root->data)
    root->left=deletenode(root->left,d);
    else if(d>root->data)
    root->right=deletenode(root->right,d);
    else{
        if(root->count>1){
            (root->count)--;
            return root;
        }
        if(root->left==NULL){
            Node* te=root->right;
            free(root);
            return te;
        }
        else if(root->right==NULL){
            Node* te=root->left;
            free(root);
            return te;
        }
        Node* te=min(root->right);
        root->data=te->data;
        root->count=te->count;
        te->count=0;
        root->right=deletenode(root->right,te->data);
    }
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

int main(){
    Node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=insert(root,x);
    }
    inorder(root);
    cout<<endl;
    Node* mi=min(root);
    cout<<mi->data<<endl;
    Node* ma=max(root);
    cout<<ma->data<<endl;
    deletenode(root,12);
    inorder(root);
    cout<<endl;
    deletenode(root,9);
    inorder(root);
    cout<<endl;
    level(root);
    return 0;
}