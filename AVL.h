#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Node.h"
using namespace std;
template<typename Temp>
class AVL
{
private:
    Node<Temp>* root;
    int getHeight(Node<Temp>* node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node<Temp>* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node<Temp>* rightRotate(Node<Temp>* y)
    {
        Node<Temp>* x = y->left;
        Node<Temp>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }

    Node<Temp>* leftRotate(Node<Temp>* x)
    {
        Node<Temp>* y = x->right;
        Node<Temp>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }
    Node<Temp>* insert(Node<Temp>* root, Temp key, string& rotatetype)
    {
        if (root == NULL)
        {
            return (new Node<Temp>(key));
        }

        if (key < root->data)
        {
            root->left = insert(root->left, key, rotatetype);
        }

        else if (key > root->data)
        {
            root->right = insert(root->right, key, rotatetype);
        }
        else
        {
            cout <<"\n" << setw(80) << "Duplicates exist" << endl;
            return root;
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        // Case 1: Left Left
        if (balance > 1 && key < root->left->data)
        {
            rotatetype = "LL";
            cout << "\n" << setw(80) << "LL case here. Right rotation is made" << endl;
            return rightRotate(root);
        }

        // Case 2: Right Right
        if (balance < -1 && key > root->right->data)
        {
            rotatetype = "RR";
            cout << "\n" << setw(80) << "RR case here. Left rotation is made" << endl;
            return leftRotate(root);
        }

        // Case 3: Left Right
        if (balance > 1 && key > root->left->data)
        {
            rotatetype = "LR";
            root->left = leftRotate(root->left);
            cout << "\n" << setw(80) << "LR here, R->L rotation is performed";
            return rightRotate(root);
        }

        // Case 4: Right Left
        if (balance < -1 && key < root->right->data)
        {
            rotatetype = "RL";
            root->right = rightRotate(root->right);

            cout << "\n" << setw(80) << "RL here, L->R rotation is performed";
            return leftRotate(root);
        }
        return root;
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

    void PreOrderTraversal(Node<Temp>* root)
    {

        if (root != NULL)
        {

            cout << root->data << " ";
            PreOrderTraversal(root->left);
            PreOrderTraversal(root->right);
        }
    }

    void PostOrderTraversal(Node<Temp>* root)
    {

        if (root != NULL)
        {

            PostOrderTraversal(root->left);
            PostOrderTraversal(root->right);

            cout << root->data << " ";
        }
    }

    Node<Temp>* searchInBST(Node<Temp>* root, Temp key)
    {
        if (root == NULL)
        {
            cout << "\n" << setw(80) << "Not Found" << endl;
            return root;
        }
        if (key == root->data)
        {
            cout << "\n" << setw(80) << "Found: " << root->data << endl;
            return root;
        }
        else if (key < root->data)
        {
            return searchInBST(root->left, key);
        }
        else if (key > root->data)
        {
            return searchInBST(root->right, key);
        }
    }
    Node<Temp>* getMinkeyueNode(Node<Temp>* node)
    {
        Node<Temp>* current = node;
        while (current->left)
            current = current->left;
        return current;
    }
    Node<Temp>* deleteNode(Node<Temp>* root, Temp key)
    {
        if (!root)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left || !root->right)
            {
                Node<Temp>* temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp; // Copy child content
                }
                delete temp;
            }
            else
            {

                Node<Temp>* temp = getMinkeyueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (!root)
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        // Case 1: Left Left
        if (balance > 1 && getBalance(root->left) >= 0)
        {
            cout << "\n" << setw(80) << "LL Rotation (Right rotation)" << endl;
            return rightRotate(root);
        }

        // Case 2: Left Right
        if (balance > 1 && getBalance(root->left) < 0)
        {
            cout << "\n" << setw(80) << "LR Rotation (Left-Right rotation)" << endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Case 3: Right Right
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            cout << "\n" << setw(80) << "RR Rotation (Left rotation)" << endl;
            return leftRotate(root);
        }

        // Case 4: Right Left
        if (balance < -1 && getBalance(root->right) > 0)
        {
            cout << "\n" << setw(80) << "RL Rotation (Right-Left rotation)" << endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insertNodes(Temp id)
    {
        string rotate = "";
        root = insert(root, id, rotate);
        if (rotate == "")
            cout << setw(80) << "No rotation  " << endl;
    }

    void inOrder()
    {
        cout << setw(80);
        inOrderTraversal(root);
    }
    void PreOrder()
    {
        cout << setw(80);
        PreOrderTraversal(root);
    }
    void PostOrder()
    {
        cout << setw(80);
        PostOrderTraversal(root);
    }
    void search(Temp search)
    {
        searchInBST(root, search);
    }
    void deleteNode(Temp val)
    {
        deleteNode(root, val);
    }
    Node<Temp>* getRoot()
    {
        return root;
    }
};
