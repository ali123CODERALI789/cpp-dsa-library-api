#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <typename Temp>
class LinkedList
{
private:
    Node<Temp>* head, * tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void append(Temp val)
    {
        Node<Temp>* newNode = new Node<Temp>(val);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void InsertAtEnd(Temp val) {
        append(val);
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void InsertAtStart(Temp val)
    {
        Node<Temp>*  newNode = new Node<Temp>(val);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert(int index,Temp val)
    {
        if (index == 0) // If inserting at the start
        {
            InsertAtStart(val);
            return;
        }

        if (!head) // If the list is empty
        {
            cout << "\n" << setw(80) << "The list is empty.";
            return;
        }

        Node<Temp>* temp = head;
        int count = 0;

        while (temp && count < index - 1) // Move to the node before the index
        {
            temp = temp->next;
            count++;
        }

        if (!temp) // If index is out of range
        {
            cout << "\n" << setw(80) << "Invalid position!\n";
            return;
        }

        if (!temp->next) // If inserting at the last position
        {
            InsertAtEnd(val);
            return;
        }

        // Insert in the middle
        Node<Temp>* newNode = new Node<Temp>(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void DeleteAtStart()
    {
        if (!head) // If list is empty
        {
            cout << "\n" << setw(80) << "List is empty";
            return;
        }

        if (head == tail) // If only one node
        {
            delete tail; // remove tail so that it's  null
            head = tail = NULL;
            return;
        }

        Node<Temp>* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteAtEnd()
    {
        if (!head) // If list is empty
        {
            cout << "\n" << setw(80) << "List is empty";
            return;
        }

        if (head == tail) // If only one node
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node<Temp>* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void remove(Temp val)
    {
        if (!head)
        {
            cout << "\n" << setw(80) << "List is empty";
            return;
        }
        if (head->data == val)
        {
            DeleteAtStart();
            return;
        }
        Node<Temp>* temp = head, * prev = NULL;
        while (temp && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "\n" << setw(80) << "Not found\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void show()
    {
        Node<Temp>* temp = head;
        cout << setw(80)<<" List: ";
        while (temp)
        {

            cout << temp->data << " ";

            temp = temp->next;
        }
        cout << endl;
    }

    void ReverseList(Node<Temp>* node)
    {
        Node<Temp>* temp = node, * prev = NULL;
        Node<Temp>* curr = NULL;
        while (temp != NULL)
        {

            curr = temp->next;
            temp->next = prev;

            prev = temp;
            temp = curr;
        }
        head = prev;

    }
    void Reverse() {
        ReverseList(head);
    }
    void Clear()
    {
        Node<Temp>* temp = head;
        if (!temp)
        {
            cout << "\n" << setw(80) << "List is empty";
            return;
        }
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }

        cout << "\n" << setw(80) << "The list is destroyed";
    }
    Node<Temp>* getHead() {
        return head;
    }
    ~LinkedList() {
        Clear();
    }
};