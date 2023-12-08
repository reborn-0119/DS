#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert an element x at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert an element x at the end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert an element x at a particular position
    void insertAtPosition(int x, int position) {
        if (position == 0) {
            insertAtBeginning(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* current = head;
        int count = 0;

        while (current) {
            if (count == position - 1) {
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
            count++;
        }

        cout << "Position out of range, element not inserted" << endl;
    }

    // Remove an element from the beginning
    void removeFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
        } else {
            cout << "List is empty, cannot remove" << endl;
        }
    }

    // Remove an element from the end
    void removeFromEnd() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = NULL;
            } else {
                head = NULL;
            }
            delete temp;
        } else {
            cout << "List is empty, cannot remove" << endl;
        }
    }

    // Remove an element from a particular position
    void removeFromPosition(int position) {
        if (position == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        int count = 0;

        while (current) {
            if (count == position) {
                current->prev->next = current->next;
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
            count++;
        }

        cout << "Position out of range, element not removed" << endl;
    }

    // Display the doubly linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "X" << endl;
    }
};

int main() {
    DoublyLinkedList doublyLinkedList;

    doublyLinkedList.insertAtBeginning(1);
    doublyLinkedList.insertAtBeginning(2);
    doublyLinkedList.insertAtBeginning(3);

    doublyLinkedList.display();

    doublyLinkedList.insertAtPosition(4, 1);
    doublyLinkedList.display();

    doublyLinkedList.insertAtEnd(5);
    doublyLinkedList.display();

    doublyLinkedList.removeFromBeginning();
    doublyLinkedList.display();

    doublyLinkedList.removeFromEnd();
    doublyLinkedList.display();

    doublyLinkedList.removeFromPosition(1);
    doublyLinkedList.display();

    return 0;
}

