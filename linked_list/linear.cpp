#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* pfirst;
public:
    SinglyLinkedList() {
        pfirst = NULL;
    }
    
    void insertAtBeginning(int data) {
        Node* pnew = new Node;
        pnew->info = data;
        pnew->next = pfirst;
        pfirst = pnew;
    }
    
    void insertAtEnd(int data) {
        Node* pnew = new Node;
        pnew->info = data;
        pnew->next = NULL;
        
        if (pfirst == NULL) {
            pfirst = pnew;
            return;
        }
        
        Node* pthis = pfirst;
        while (pthis->next != NULL)
            pthis = pthis->next;
        
        pthis->next = pnew;
    }
    
    void insertBeforePosition(int data, int loc) {
        if (loc <= 1) {
            insertAtBeginning(data);
            return;
        }
        
        Node* pnew = new Node;
        pnew->info = data;
        
        Node* pthis = pfirst;
        for (int i = 1; i < loc - 1 && pthis->next != NULL; i++)
            pthis = pthis->next;
        
        Node* ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
    
    void insertAfterPosition(int data, int loc) {
        Node* pnew = new Node;
        pnew->info = data;
        
        Node* pthis = pfirst;
        for (int i = 1; i < loc && pthis != NULL; i++)
            pthis = pthis->next;
        
        if (pthis == NULL) return;
        
        Node* ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
    
    void deleteFromBeginning() {
        if (pfirst == NULL) return;
        
        Node* ptemp = pfirst;
        pfirst = pfirst->next;
        delete ptemp;
    }
    
    void deleteFromEnd() {
        if (pfirst == NULL) return;
        
        if (pfirst->next == NULL) {
            delete pfirst;
            pfirst = NULL;
            return;
        }
        
        Node* pthis = pfirst;
        while (pthis->next->next != NULL)
            pthis = pthis->next;
        
        delete pthis->next;
        pthis->next = NULL;
    }
    
    void deleteAtPosition(int loc) {
        if (pfirst == NULL || loc <= 0) return;
        
        if (loc == 1) {
            deleteFromBeginning();
            return;
        }
        
        Node* pthis = pfirst;
        for (int i = 1; i < loc - 1 && pthis->next != NULL; i++)
            pthis = pthis->next;
        
        if (pthis->next == NULL) return;
        
        Node* ptemp = pthis->next->next;
        delete pthis->next;
        pthis->next = ptemp;
    }
    
    void display() {
        Node* pthis = pfirst;
        while (pthis != NULL) {
            cout << pthis->info << " -> ";
            pthis = pthis->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertBeforePosition(25, 2);
    list.insertAfterPosition(15, 1);
    list.display();
    
    list.deleteFromBeginning();
    list.display();
    
    list.deleteFromEnd();
    list.display();
    
    list.deleteAtPosition(2);
    list.display();
    
    return 0;
}
