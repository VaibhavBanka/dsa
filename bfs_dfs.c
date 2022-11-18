#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *next;
}*front = NULL,*rear = NULL;
void enqueue(int element){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = element;
    if(front == NULL){
        front = rear = temp;
    } 
    else{
        rear->next = temp;
        rear = temp;
    }
}
int dequeue(){
    if(front == NULL){
        printf("queue is empty\n");
    }
    else{
        struct node *temp = front;
        front = front->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}
bool isempty(){
    return front == NULL;
}
void display(){
    struct node* temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void bfs(int g[][6], int start, int n){
    int visited[6+1] = {0};
    int i = start;
    printf("%d ",i);
    visited[i] = 1;
    enqueue(i);
    while(!isempty()){
        i = dequeue();
        for(int j = 1;j<=n;j++){
            if(g[i][j] && !visited[j]){
                printf("%d ",j);
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}
void dfs(int g[][6], int start, int n){
    static int visited[6+1] = {0};
    int i = start;
    if(visited[i] == 0){
        printf("%d ",i);
        visited[i] = 1;
        for(int j = 1;j<=n;j++){
            if(g[i][j] && !visited[j]){
                dfs(g,j,n);
            }
        }
    }
}
int main(){
    int g[6][6] = {
    {0,1,1,0,0,0},
    {1,0,0,1,0,0},
    {1,0,0,1,0,0},
    {0,1,1,0,1,1},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0}};
    // int g[5][5] = {{0, 9, 75, 0, 0},{9, 0, 95, 19, 42},{75, 95, 0, 51, 66},{0, 19, 51, 0, 31},{0, 42, 66, 31, 0}};
    bfs(g,1,6);
    printf("\n");
    dfs(g,4,6);
}
