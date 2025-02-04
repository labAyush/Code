#include <iostream>
#define max 5
using namespace std;

int queue[max];
int front = -1, rear = -1;

void enqueue(int data) {
    // Check if the queue is full
    if ((rear + 1) % max == front) {
        cout << "Queue is overflow.\n";
        return;
    }
    
    // If the queue is empty
    if (front == -1) {
        front = 0; // Initialize front
    }
    
    // Update rear index in a circular manner
    rear = (rear + 1) % max;
    queue[rear] = data; // Add the new data
    cout << data << " added.\n";
}

void dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        cout << "Queue is underflow\n";
        return;
    }
    
    cout << queue[front] << " removed.\n";
    
    // If the queue becomes empty after this dequeue
    if (front == rear) {
        front = rear = -1; // Reset the queue
    } else {
        // Update front index in a circular manner
        front = (front + 1) % max;
    }
}

int main() {
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
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}