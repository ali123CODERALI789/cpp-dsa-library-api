#pragma once
#include <iostream>
#include "Node.h"
using namespace std;


template <typename Temp>
class DoublyLinkedList {
private:
    Node<Temp>* head;  // Points to first node
    Node<Temp>* tail;  // Points to last node

public:
    // Constructor (Initially list is empty)
    DoublyLinkedList() {
        head = tail = NULL;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    // ===============================
    // INSERT AT END
    // ===============================
    void append(Temp val) {
        Node<Temp>* newNode = new Node<Temp>(val);

        if (!head) {  // If list is empty
            head = tail = newNode;
        }
        else {
            tail->next = newNode;  // Current tail's next points to new node
            newNode->prev = tail;  // New node's prev points to current tail
            tail = newNode;        // Update tail to new node
        }
    }

    // ===============================
    // INSERT AT START
    // ===============================
    void InsertAtStart(Temp val) {
        Node<Temp>* newNode = new Node<Temp>(val);

        if (!head) {  // If list is empty
            head = tail = newNode;
        }
        else {
            newNode->next = head;  // New node's next points to current head
            head->prev = newNode;  // Current head's prev points to new node
            head = newNode;        // Update head to new node
        }
    }

    // ===============================
    // INSERT AT INDEX
    // ===============================
    void insert(int index,Temp val) {
        if (index == 0) {  // If inserting at start
            InsertAtStart(val);
            return;
        }

        Node<Temp>* temp = head;
        int count = 0;

        while (temp && count < index - 1) {  // Move to node before index
            temp = temp->next;
            count++;
        }
        if (!head) {
            cout << "\n" << setw(80) << "List is empty";
            return;
        }

        if (!temp) {
            cout << "\n" << setw(80) << "Invalid position!\n";
            return;
        }

        Node<Temp>* newNode = new Node<Temp>(val);
        newNode->next = temp->next;  // New node's next points to next node
        newNode->prev = temp;        // New node's prev points to current node

        if (temp->next) {
            temp->next->prev = newNode;  // Next node's prev points to new node
        }

        temp->next = newNode;  // Current node's next points to new node

        if (!newNode->next) {  // If inserted at end, update tail
            tail = newNode;
        }



    }

    // ===============================
    // DELETE AT START
    // ===============================
    void DeleteAtStart() {
        if (!head) {  // If list is empty
            cout << "\n" << setw(80) << "List is empty";
            return;
        }

        if (head == tail) {  // If only one node
            delete head;
            head = tail = NULL;
            return;
        }

        Node<Temp>* temp = head;
        head = head->next;   // Move head to next node
        head->prev = NULL;   // New head's prev should be NULL
        delete temp;
    }

    // ===============================
    // DELETE AT END
    // ===============================
    void DeleteAtEnd() {
        if (!head) {  // If list is empty
            cout << "\n" << setw(80) << "List is empty";
            return;
        }

        if (head == tail) {  // If only one node
            delete head;
            head = tail = NULL;
            return;
        }

        Node<Temp>* temp = tail;
        tail = tail->prev;  // Move tail to previous node
        tail->next = NULL;  // New tail's next should be NULL
        delete temp;
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
        if (tail->data == val )
        {
            DeleteAtEnd();
            return;
        }
        Node<Temp>* temp = head, * pre = NULL;
        while (temp && temp->data != val)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp==NULL) {
            cout << "\n" << setw(80) << "Not found\n";
            return;
        }
        pre->next = temp->next;
        temp->next->prev = pre;
        delete temp;
    }

    // ===============================
    // DISPLAY FORWARD
    // ===============================
    void show() {
        Node<Temp>* temp = head;
        cout << setw(80) << " List: ";
        while (temp) {
            cout  << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ===============================
    // DISPLAY BACKWARD
    // ===============================
    void showreverse() {
        Node<Temp>* temp = tail;
        cout << setw(80)<<" List: ";
        
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout  << endl;
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

            head->prev = NULL;
            head = head->next;
            delete temp;
            temp = head;
        }

    }

    ~DoublyLinkedList() {
        Clear();
    }
};