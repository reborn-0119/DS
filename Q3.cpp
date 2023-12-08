#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert an element x in the list
    void insert(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Remove an element from the list
    void remove(int x) {
        if (!head) {
            cout << "List is empty, cannot remove" << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        do {
            if (current->data == x) {
                if (prev) {
                    prev->next = current->next;
                    if (current == head) {
                        head = current->next;
                    }
                    delete current;
                    return;
                } else {
                    // Removing the head node
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    if (head->next == head) {
                        // Only one node in the list
                        head = NULL;
                    } else {
                        head = head->next;
                        temp->next = head;
                    }
                    delete current;
                    return;
                }
            }

            prev = current;
            current = current->next;

        } while (current != head);

        cout << "Element not found, cannot remove" << endl;
    }

    // Search for an element x in the list and return its pointer
    Node* search(int x) {
        if (!head) {
            return NULL;
        }

        Node* current = head;
        do {
            if (current->data == x) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return NULL; // Element not found
    }

    // Reverse the list
    void reverse() {
        if (!head) {
            return;
        }

        Node* prev = NULL;
        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        head = prev;
    }

    // Display the circular linked list
    void display() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "X" << endl;
    }
};

int main() {
    CircularLinkedList circularLinkedList;

    circularLinkedList.insert(1);
    circularLinkedList.insert(2);
    circularLinkedList.insert(3);

    circularLinkedList.display();

    circularLinkedList.remove(2);
    circularLinkedList.display();

    Node* searchResult = circularLinkedList.search(1);
    if (searchResult) {
        cout << "Found: " << searchResult->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    circularLinkedList.reverse();
    circularLinkedList.display();

    return 0;
}

