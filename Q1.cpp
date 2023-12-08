#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
		data=value;
		next=NULL;
	}
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList(){
		head=NULL;
		tail=NULL;
	}
    // Insert an element x at the beginning 
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;

        if (!tail) {
            tail = head;
        }
    }

    // Insert an element x at i-th position 
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
                newNode->next = current->next;
                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
                return;
            }
            current = current->next;
            count++;
        }

        cout << "Position out of range, element not inserted" << endl;
    }

    // Insert an element x at the end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove an element from the beginning
    void removeFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty, cannot remove" << endl;
        }
    }

    // Remove an element from i-th position
    void removeFromPosition(int position) {
        if (position == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        int count = 0;

        while (current) {
            if (count == position) {
                previous->next = current->next;
                if (current == tail) {
                    tail = previous;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
            count++;
        }

        cout << "Position out of range, element not removed" << endl;
    }

    // Search for an element x in the singly linked list and return its pointer
    Node* search(int x) {
        Node* current = head;
        while (current) {
            if (current->data == x) {
                return current;
            }
            current = current->next;
        }
        return NULL; // Element not found
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "X" << endl;
    }
};

int main() {
    SinglyLinkedList linkedList;
    
    linkedList.insertAtBeginning(1);
    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(3);

    linkedList.display();

    linkedList.insertAtPosition(4, 1);
    linkedList.display();

    linkedList.insertAtEnd(5);
    linkedList.display();

    linkedList.removeFromBeginning();
    linkedList.display();

    linkedList.removeFromPosition(1);
    linkedList.display();

    Node* searchResult = linkedList.search(2);
    if (searchResult) {
        cout << "Found: " << searchResult->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

