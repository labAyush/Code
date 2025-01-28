#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int queue[MAX], front = -1, rear = -1;

public:
    void enqueue(int data) {
        if ((rear + 1) % MAX == front) return void(cout << "Queue is full!\n");
        if (front == -1) front = 0;
        queue[rear = (rear + 1) % MAX] = data;
        cout << data << " added to the queue.\n";
    }

    void dequeue() {
        if (front == -1) return void(cout << "Queue is empty!\n");
        cout << queue[front] << " removed from the queue.\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void display() {
        if (front == -1) return void(cout << "Queue is empty!\n");
        cout << "Queue contents: ";
        for (int i = front;; i = (i + 1) % MAX) {
            cout << queue[i] << " ";
            if (i == rear) break;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, data;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) cin >> data, q.enqueue(data);
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
        else if (choice == 4) return cout << "Goodbye!\n", 0;
        else cout << "Invalid choice.\n";
    }
}