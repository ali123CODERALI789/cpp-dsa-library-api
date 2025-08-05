#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <typename Temp>
class Stack {
private:
    Node<Temp>* top;

public:
    Stack() {
        top = NULL;
    }

    void push(Temp val) {
        Node<Temp>* newNode = new Node<Temp>(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << setw(80) << "Stack is empty!" << endl;
            return;
        }
        Node<Temp>* temp = top;
        top = top->next;
        delete temp;
    }

    Temp peek() {
        if (!top) {
            cout << setw(80) << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    void show() {
        if (!top) {
            cout << setw(80) << "Stack is empty!" << endl;
            return;
        }
        Node<Temp>* temp = top;
        cout << setw(80) << "Stack : ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) {
            pop();
        }
    }
};
