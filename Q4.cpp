#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack;
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '^':
                    stack.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid postfix expression" << endl;
                    return INT_MIN;
            }
        }
    }
    return stack.pop();
}

int evaluatePrefix(const string& expression) {
    Stack stack;
    for (int i = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand1 = stack.pop();
            int operand2 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '^':
                    stack.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid prefix expression" << endl;
                    return INT_MIN;
            }
        }
    }
    return stack.pop();
}

int main() {
    string postfixExpression = "23*5+";
    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Postfix Result: " << evaluatePostfix(postfixExpression) << endl;

    string prefixExpression = "+*258";
    cout << "Prefix Expression: " << prefixExpression << endl;
    cout << "Prefix Result: " << evaluatePrefix(prefixExpression) << endl;

    return 0;
}

