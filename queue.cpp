#include <iostream>
using namespace std;
class queue{
public:
    int *arr;
    int size;
    int front;
    int rear;
    queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void is_full(){
        if (rear >= size){
            cout << "Queue is full" << endl;
        }
    }
    void is_empty(){
        if (rear==front){
            cout << "Queue is empty";
        }
    }
    void push(int element){
        if (rear >= size){
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear] = element;
            rear++;
        }
    }
    void pop(){
        if (rear==front){
            cout << "Queue is empty"<<endl;
        }
        else{
            cout<<arr[front]<<" just got popped"<<endl;
            arr[front] = -1;
            front++;
            if(front==rear){
                front = 0;
                rear = 0;
            }
        }
    }
    void frnt(){
        if (rear==front){
            cout << "Queue is empty";
        }
        else{
            cout<<"The element in the front is:"<<arr[front]<<endl;
        }
    }
    void print(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    queue q1(5);
    q1.push(10);
    q1.push(20);
    q1.print();
    q1.pop();
    q1.pop();
    q1.print();
    q1.pop();
}
