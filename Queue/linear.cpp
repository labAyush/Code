#include <iostream>
#define MAX 5
using namespace std;

class LinearQueue {
private:
    int queue[MAX];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int data) {
        if (rear == MAX - 1) {
            cout << "Queue is full!\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = data;
        cout << data << " added to the queue.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty! Nothing to remove.\n";
            return;
        }

        int data = queue[front];
        cout << data << " removed from the queue.\n";

        if (front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    LinearQueue q;
    int choice, data;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add to queue (Enqueue)\n";
        cout << "2. Remove from queue (Dequeue)\n";
        cout << "3. Show queue contents\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a number to add: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}