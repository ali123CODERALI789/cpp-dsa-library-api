#define ASIO_STANDALONE

// STL includes first
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Your renamed headers
#include "MyMath.h"
#include "Sorting.h"
#include "Searching.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "DynamicArray.h"
#include "BST.h"
#include "AVL.h"
#include "Graph.h"

// Crow last
#include "crow_all.h"
#include "API.h"
#include "Testing.h"


using namespace std;

int main() {
    int choice;
    cout << setw(80) << "Choose Mode:\n";
    cout << setw(80) << "1. CLI Testing\n";
    cout << setw(80) << "2. Start API Server\n";
    cin >> choice;

    if (choice == 1) {
        runTests();
    }
    else if (choice == 2) {
        runCrowServer();
    }
    else {
        cout << setw(80) << "Invalid option.\n";
    }
    return 0;
}
