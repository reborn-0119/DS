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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) {
            rear = NULL;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot peek" << endl;
            return INT_MIN;
        }

        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        while (current) {
            cout << current->data << " <- ";
            current = current->next;
        }
        cout << "X" << endl;
    }
};

int main() {
    Queue queue;

    cout << "Enqueue 1, 2, 3" << endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();

    cout << "Dequeue" << endl;
    queue.dequeue();
    queue.display();

    cout << "Enqueue 4" << endl;
    queue.enqueue(4);
    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    return 0;
}

