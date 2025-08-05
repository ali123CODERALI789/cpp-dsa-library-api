#pragma once
#include <iostream>
using namespace std;
template<typename Temp>
class Node
{
public:
    Node<Temp>* next,*left,*right;
    Temp data;int height;
    Node<Temp>* prev;  // Points to the previous node

    Node(Temp val) {
        data = val;
        height = 0;
        next = prev = nullptr;
        left = right = nullptr;
    }
};