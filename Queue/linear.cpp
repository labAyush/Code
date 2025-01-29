#include<iostream>
#define max 5
using namespace std;
int queue[max];
int front=-1,rear=-1;
void enqueue(int data){
    if(rear==max-1){
        cout<<"Queue is overflow.\n";
        return;
    }
    if (front==-1){
        front=0;
    }
    rear=rear+1;
    queue[rear]=data;
    cout<<data<<" added.\n";
}
void dequeue(){
    if (front=-1){
        cout<<"Queue is underflow.\n";
        return;
    }
    int data=queue[front];
    cout<<data<<" removed.\n";
    if (front>rear){
        front=-1;
        rear=-1;
    }else{
        front=front+1;
    }
}
int main(){
    int choice,data;
    while(true){
    cout << "1.Enqueue\t2.Dequeue\t3.Exit\n";
    cout << "Choose an option:\n";
    cin >> choice;
    switch(choice){
        case 1:
            cout<<"enter the number to enqueue:";
            cin>>data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return 0;
        default:
            cout<<"invalid choice.\n";
    }
	}
    return 0;
}
