#include <iostream>
#define max 5
using namespace std;
int queue[max];
int front = -1, rear = -1;
void enqueue(int data) {
	if((rear==max-1&&front==0)||front==(rear+1))
	{
		cout << "Queue is overflow.\n";
        return;
	}
    else if ((rear+1)%max == front) {
        rear = (rear+1)%max;
    }
    else if (front == -1){
		front = 0;
	}
    queue[rear] = data;
    cout << data << " added.\n";
}
void dequeue() {
    if (front == -1) {
        cout <<"Queue is underflow\n";
        return;
    }
    cout << queue[front] << " removed.\n";
    if (front == rear) front = rear = -1;
    else front = (front+1)%max;
}
int main(){
    int choice, data;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter data to enqueue: ";
            cin >> data;
            enqueue(data);
        } else if (choice == 2) {
            dequeue();
        }else if (choice == 3) {
            break;
        } else {
            cout << "invalid choice.\n";
        }
    }
    return 0;
}
