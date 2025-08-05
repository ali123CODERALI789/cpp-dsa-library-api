#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
template<typename Temp>
class QueueNode
{
public:
    Node<Temp>* treeNode;
    QueueNode<Temp>* next;
    QueueNode(Node<Temp>* node)
    {
        treeNode = node;
        next = NULL;
    }
};

template<typename Temp>
class QueueBST
{
private:
    QueueNode<Temp>* front, * rear;

public:
    QueueBST()
    {
        front = rear = NULL;
    }

    void enqueue(Node<Temp>* node)
    {
        QueueNode<Temp>* newNode = new QueueNode<Temp>(node);
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node<Temp>* dequeue()
    {
        if (front == NULL)
            return NULL;
        QueueNode<Temp>* temp = front;
        Node<Temp>* retNode = temp->treeNode;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return retNode;
    }

    bool isEmpty()
    {
        return front == NULL;
    }
};

template<typename Temp>
class BST
{
private:
    int count;
    Node<Temp>* root;

    Node<Temp>* insertNode(Node<Temp>* root, Temp val)
    {
        if (root == NULL)
        {
            return (new Node<Temp>(val));
        }
        if (val < root->data)
        {
            root->left = insertNode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    bool searchNode(Node<Temp>* root, Temp val)
    {
        if (root == NULL)
            return false;
        if (root->data == val)
            return true;
        if (val < root->data)
            return searchNode(root->left, val);
        else
            return searchNode(root->right, val);
    }

    int findDepth(Node<Temp>* root, Temp val, int count)
    {
        if (root == NULL)
        {
            cout << "\n" << setw(80) << "Not found" << endl;
            return -1;
        }
        if (root->data == val)
        {
            return count;
        }
        else if (val < root->data)
        {
            return findDepth(root->left, val, count + 1);
        }
        else
        {
            return findDepth(root->right, val, count + 1);
        }
    }

    int Height(Node<Temp>* root)
    {
        if (root == NULL)
            return -1;
        int leftheight = Height(root->left);
        int rightheight = Height(root->right);
        return (leftheight > rightheight) ? leftheight + 1 : rightheight + 1;
    }

    Node<Temp>* inordersuccessor(Node<Temp>* root)
    {
        Node<Temp>* temp = root;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node<Temp>* deletenode(Node<Temp>* root, Temp val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (val < root->data)
        {
            root->left = deletenode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = deletenode(root->right, val);
        }
        else
        {
            if (root->left == NULL)
            {
                Node<Temp>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node<Temp>* temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node<Temp>* temp = inordersuccessor(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }
        return root;
    }

public:
    BST()
    {
        count = 0;
        root = NULL;
    }

    void Insert(Temp val)
    {
        root = insertNode(root, val);
    }

    bool Search(Temp key)
    {
        return searchNode(root, key);
    }

    int finddepth(Temp val)
    {
        return findDepth(root, val, count);
    }

    int height()
    {
        return Height(root);
    }

    void Delete(Temp val)
    {
        root = deletenode(root, val);
    }

    void BFS()
    {
        if (root == NULL)
        {
            cout << "\n" << setw(80) << "Tree is empty.\n";
            return;
        }

        QueueBST<Temp> q;
        q.enqueue(root);
        cout << setw(80);
        while (!q.isEmpty())
        {
            Node<Temp>* current = q.dequeue();
            cout << current->data << " ";

            if (current->left)
                q.enqueue(current->left);
            if (current->right)
                q.enqueue(current->right);
        }
        cout << endl;
    }

    void inOrderTraversal(Node<Temp>* root)
    {
        if (root != NULL)
        {
            inOrderTraversal(root->left);
            cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    void PreorderTraversal(Node<Temp>* root)
    {
        if (root != NULL)
        {
            cout << root->data << " " << endl;
            PreorderTraversal(root->left);
            PreorderTraversal(root->right);
        }
    }

    void PostorderTraversal(Node<Temp>* root)
    {
        if (root != NULL)
        {
            PostorderTraversal(root->left);
            PostorderTraversal(root->right);
            cout << root->data << " " << endl;
        }
    }

    void inOrderTraversal()
    {
        cout << setw(80);
        inOrderTraversal(root);
    }

    void PreorderTraversal()
    {
        cout << setw(80);
        PreorderTraversal(root);
    }

    void PostorderTraversal()
    {
        cout << setw(80);
        PostorderTraversal(root);
    }
};
