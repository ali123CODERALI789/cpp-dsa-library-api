#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <typename Temp>
class Queue
{
private:
    Node<Temp>* front;
    Node<Temp>* rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(Temp val)
    {
        Node<Temp>* newNode = new Node<Temp>(val);

        if (!rear)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\n" << setw(80) << "Queue is empty!\n";
            return;
        }

        Node<Temp>* temp = front;
        front = front->next;

        if (!front)
            rear = NULL;

        delete temp;
    }

    Temp peek()
    {
        if (isEmpty())
        {
            cout << "\n" << setw(80) << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void show()
    {
        if (isEmpty())
        {
            cout << "\n" << setw(80) << "Queue is empty!\n";
            return;
        }

        Node<Temp>* temp = front;
        cout<< setw(80) << " Queue: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }


    
};

