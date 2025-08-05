#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<typename Temp>
class CircularLinkedList
{
private:
    Node<Temp>* head, * tail;

public:
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtEnd(Temp val)
    {
        Node<Temp>* newNode = new Node<Temp>(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void Display()
    {
        Node<Temp>* temp = head;
        cout << setw(80) << " List: ";
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << setw(80) << " NULL" << endl;
    }



    void ReverseKGroups(int k) {
        if (!head || k <= 1) {
            return;
        }

        Node<Temp>* temp = head;
        Node<Temp>* end = NULL;

        while (temp) {
            int count = 0;
            Node<Temp>* start = temp;
            Node<Temp>* before = NULL;

            // Check if there are at least k Nodes left
            Node<Temp>* check = temp;
            int i = 0;
            while (i < k) {
                if (!check)
                    return; // If fewer than k Nodes remain, do not reverse
                check = check->next;
                i++;
            }


            // Reverse k Nodes
            while (count < k && temp) {
                Node<Temp>* after = temp->next;

                temp->next = before;

                if (before) {
                    before->prev = temp; // Fix prev pointer
                }

                before = temp;
                temp = after;
                count++;
            }

            // Connect previous group
            if (!end) {
                head = before; // Update head if it's the first group
            }
            else {
                end->next = before;
                if (before) before->prev = end;
            }

            start->next = temp; // Connect last Node of reversed group to next group
            if (temp) {
                temp->prev = start;
            }
            end = start; // Move `end` to the new last Node of the reversed group
        }
    }bool isEmpty() {
        return head == nullptr;
    }
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
    ~CircularLinkedList() {
        while (!isEmpty()) {
            DeleteAtEnd();
        }
    }
};
