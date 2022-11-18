#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b=n*(n-1);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int edges=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1)
            edges+=1;
        }
    }
    if(edges==b)
    cout<<"yes";
    else
    cout<<"no";
}