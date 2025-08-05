#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
template<typename Temp>
class QNode
{
public:
    QNode<Temp>* next;
    Temp data;
    QNode(Temp val)
    {
        next = NULL;
        data = val;
    }
};
template<typename Temp>
class QueueGraph
{
private:
    QNode<Temp>* front, * rear;

public:
    QueueGraph()
    {
        front = rear = NULL;
    }
    void Enqueue(Temp n)
    {
        QNode<Temp>* newNode = new QNode<Temp>(n);
        if (!front)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    Temp Dequeue()
    {
        if (front == NULL)
        {
            return Temp();
        }
        QNode<Temp>* temp = front;
        Temp val = temp->data;

        front = front->next;

        if (front == NULL)
        {
            front = rear = NULL;
        }
        delete temp;
        return val;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
};
template<typename Temp>
class Graph
{
private:
    Node<Temp>** adjList;
    int nodes;
    bool* visited;

public:
    Graph(int n)
    {
        nodes = n;
        visited = new bool[nodes];
        adjList = new Node<Temp>* [nodes];
        for (int i = 0; i < nodes; i++)
        {
            adjList[i] = NULL;
            visited[i] = false;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < nodes; i++)
        {

            Node<Temp>* temp = adjList[i];
            while (temp)
            {
                Node<Temp>* curr = temp;
                temp = temp->next;
                delete curr;
            }
        }
        delete[] adjList;
        delete[] visited;
    }

    void addEdge(int u, int v)
    {
        if (u < 0 || u >= nodes || v < 0 || v >= nodes)
            return;

        Node<Temp>* newNode = new Node<Temp>(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = new Node<Temp>(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    void display() const
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << ": ";
            Node<Temp>* temp = adjList[i];
            while (temp)
            {
                cout << temp->data;
                if (temp->next)
                    cout << " - ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void BFS(Temp start)
    {
        visited[start] = true;
        QueueGraph<Temp> q;
        cout << setw(80);
        q.Enqueue((start)); 
        while (!q.isEmpty())
        {
            Temp val = q.Dequeue();
            cout << val << " ";
            Node<Temp>* curr = adjList[val];
            while (curr)
            {
                int v = curr->data;
                if (visited[v] != true)
                {
                    visited[v] = true;
                    q.Enqueue(v);
                }
                curr = curr->next;
            }
        }
    }

    void bfsShortestpath(Temp start)
    {
        bool* visited = new bool[nodes];
        int* path = new int[nodes];

        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
            path[i] = -1;
        }

        QueueGraph<Temp> q;
        visited[start] = true;
        path[start] = 0;
        q.Enqueue(start);

        while (!q.isEmpty())
        {
            Temp u = q.Dequeue();

            Node<Temp>* temp = adjList[u];
            while (temp != NULL)
            {
                int v = temp->data;
                if (!visited[v])
                {
                    visited[v] = true;
                    path[v] = path[u] + 1;
                    q.Enqueue(v);
                }
                temp = temp->next;
            }
        }

        cout << "\n" << setw(80) << "Shortest paths from node " << start << ":\n";
        for (int i = 0; i < nodes; i++)
        {
            cout << "\n" << setw(80) << "To " << i << ": " << path[i] << endl;
        }

        delete[] visited;
        delete[] path;
    }

    void DFS(Temp start, bool visited[])
    {
        visited[start] = true;
        cout << " " << start;
        Node<Temp>* temp = adjList[start];
        while (temp)
        {
            int val = temp->data;
            if (!visited[val])
            {
                DFS(val, visited);
            }
            temp = temp->next;
        }
    }


    void DFS(Temp start)
    {
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }
        cout << setw(80);
        DFS(start, visited);
    }
};

