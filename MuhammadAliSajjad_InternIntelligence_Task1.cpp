#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Math.h"
#include "Searching.h"
#include "Sorting.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "DynamicArray.h"
#include "BST.h"
#include "AVL.h"
#include "Graph.h"

using namespace std;

int main() {

    // =========================
    //       Math Functions
    // =========================
    cout << setw(80) << "=== DEMO: Math Functions ===\n";
    Math math;
    cout << setw(80) << "Abs(-10): " << math.Abs(-10) << endl;
    cout << setw(80) << "IsPrime(7): " << math.isPrime(7) << endl;
    cout << setw(80) << "Factorial(5): " << math.factorial(5) << endl;
    cout << setw(80) << "ReverseNumber(12345): " << math.ReverseNumber(12345) << endl;
    cout << setw(80) << "GCD(20, 8): " << math.GCD(20, 8) << endl;
    cout << setw(80) << "LCM(4, 6): " << math.LCM(4, 6) << endl;
    cout << setw(80) << "Power(2, 4): " << math.power(2, 4) << endl;
    cout << setw(80) << "IsPalindrome(121): " << math.isPalindrome(121) << endl;
    cout << setw(80) << "SumOfDigits(123): " << math.sumOfDigits(123) << endl;
    cout << setw(80) << "IsEven(10): " << math.isEven(10) << endl;
    cout << setw(80) << endl;

    // =========================
    //           Stack
    // =========================
    cout << setw(80) << "=== DEMO: Stack ===\n";
    Stack<int> stack;
    stack.push(10); stack.push(20); stack.push(30);
    stack.show();
    cout << setw(80) << "Top: " << stack.peek() << endl;
    stack.pop();
    stack.show();
    cout << setw(80) << endl;

    // =========================
    //           Queue
    // =========================
    cout << setw(80) << "=== DEMO: Queue ===\n";
    Queue<int> queue;
    queue.enqueue(100); queue.enqueue(200); queue.enqueue(300);
    queue.show();
    queue.dequeue();
    queue.show();
    cout << setw(80) << "Peek: " << queue.peek() << endl << endl;

    // ================================
    //       Singly Linked List
    // ================================
    cout << setw(80) << "=== DEMO: Singly Linked List ===\n";
    LinkedList<int> list;
    list.append(1); list.append(2); list.append(3);
    list.InsertAtStart(0);
    list.insert(99, 2);
    list.show();
    list.remove(2);
    list.show();
    list.Reverse();
    list.show();
    list.Clear();
    cout << setw(80) << endl;

    // =========================
    //        Vector Array
    // =========================
    cout << setw(80) << "=== DEMO: VectorArray ===\n";
    VectorArray<int> vec;
    vec.push_back(10); vec.push_back(20); vec.push_back(30);
    vec.show();
    vec.insert(15, 2); vec.show();
    vec.erase(2); vec.show();
    vec.resize(5); vec.show();
    vec.assign(7, 2); vec.show();
    vec.clear(); vec.show();
    cout << setw(80) << endl;

    // =========================
    //        Sorting Demos
    // =========================
    cout << setw(80) << "=== DEMO: Sorting Algorithms ===\n";
    int arr1[5] = { 5, 2, 8, 1, 9 };
    int arr2[5] = { 12, 3, 7, 4, 2 };
    int arr3[5] = { 15, 11, 6, 4, 9 };

    cout << setw(80) << "Original Array 1: "; show(arr1);
    cout << setw(80) << "\nBubble Sorted: "; BubbleSort(arr1); show(arr1); cout << setw(80) << endl;

    cout << setw(80) << "Original Array 2: "; show(arr2);
    cout << setw(80) << "\nSelection Sorted (Descending): "; sort(arr2); show(arr2); cout << setw(80) << endl;

    cout << setw(80) << "Original Array 3: "; show(arr3);
    cout << setw(80) << "\nInsertion Sorted (Descending): "; sort(arr3); show(arr3); cout << setw(80) << endl;

    // =========================
    //         Extra Math
    // =========================
    cout << setw(80) << "=== EXTRA: Math Edge Cases ===\n";
    cout << setw(80) << "Abs(0): " << math.Abs(0) << endl;
    cout << setw(80) << "IsPrime(1): " << math.isPrime(1) << endl;
    cout << setw(80) << "Factorial(0): " << math.factorial(0) << endl;
    cout << setw(80) << "GCD(0, 5): " << math.GCD(0, 5) << endl;
    cout << setw(80) << "LCM(0, 6): " << math.LCM(0, 6) << endl;
    cout << setw(80) << "IsPalindrome(1221): " << math.isPalindrome(1221) << endl << endl;

    // ================================
    //     Stack/Queue Edge Testing
    // ================================
    cout << setw(80) << "=== EXTRA: Stack Mixed Operations ===\n";
    stack.push(40); stack.push(50);
    stack.pop(); stack.show();
    stack.pop(); stack.pop(); stack.pop();  // Underflow
    cout << setw(80) << endl;

    cout << setw(80) << "=== EXTRA: Queue Mixed Operations ===\n";
    queue.enqueue(400); queue.enqueue(500);
    queue.dequeue(); queue.dequeue(); queue.dequeue(); // Underflow
    cout << setw(80) << endl;

    // =========================
    //     Linked List Deep Test
    // =========================
    cout << setw(80) << "=== EXTRA: Linked List Deep Test ===\n";
    list.append(5); list.append(10);
    list.insert(15, 1); list.insert(25, 2);
    list.show();
    list.DeleteAtStart(); list.DeleteAtEnd();
    list.show(); list.Reverse(); list.show(); list.Clear();
    cout << setw(80) << endl;

    // =========================
    // Circular Linked List with Menu
    // =========================
    cout << setw(80) << "=== DEMO: Circular Linked List Menu ===\n";
    CircularLinkedList<int> c;
    int choice, value, k;
    bool game = true;
    while (game) {
        cout << setw(80) << "\n\n-- Reversing in k Groups --\n";
        cout << setw(80) << "1. Insert at end\n2. Delete at end\n3. Display List\n4. Reverse in Groups\n5. Check Empty\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << setw(80) << "Enter number: "; cin >> value; c.InsertAtEnd(value); break;
        case 2: c.DeleteAtEnd(); break;
        case 3: c.Display(); break;
        case 4: cout << setw(80) << "Enter k: "; cin >> k; c.ReverseKGroups(k); break;
        case 5: cout << setw(80) << (c.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
        case 6: game = false; break;
        default: cout << setw(80) << "Invalid choice.\n";
        }
    }

    // ================================
    //     VectorArray Functionalities
    // ================================
    cout << setw(80) << "=== EXTRA: VectorArray Functionalities ===\n";
    vec.push_back(1); vec.push_back(2); vec.push_back(3);
    vec.insert(9, 2); vec.insert(99, 1);
    vec.show();
    vec.erase(3); vec.show();
    vec.assign(111, 2); vec.show();
    vec.assign(7, 1, vec.getsize()); vec.show();
    vec.find(7); vec.find(100);
    vec.clear(); vec.show();
    cout << setw(80) << endl;

    // =========================
    //     Sorting - Other Types
    // =========================
    cout << setw(80) << "=== EXTRA: Sorting Float Array ===\n";
    float arrf[] = { 2.5, 1.1, 4.4, 0.9 };
    cout << setw(80) << "Original: "; show(arrf);
    cout << setw(80) << "\nSorted: "; BubbleSort(arrf); show(arrf); cout << setw(80) << endl;

    cout << setw(80) << "=== FINAL: Sorting Chars ===\n";
    char arrc[] = { 'z', 'b', 'x', 'a' };
    cout << setw(80) << "Original: "; show(arrc);
    cout << setw(80) << "\nSorted: "; sort(arrc); show(arrc); cout << setw(80) << endl;

    // =========================
    //       Searching
    // =========================
    int arr[] = { 5, 10, 15, 20, 25, 30 };
    int size = sizeof(arr) / sizeof(arr[0]);
    value = 20;

    cout << setw(80) << "\n=== DEMO: Searching ===\nArray: ";
    for (int i = 0; i < size; ++i) cout << setw(80) << arr[i] << " ";
    cout << setw(80) << endl;

    int linearResult = LinearSearch<int>(arr, size, value);
    cout << setw(80) << (linearResult != -1 ? "Linear Search: Found at index " + to_string(linearResult + 1) : "Linear Search: Not found") << endl;

    int binaryResult = BinarySearch<int>(arr, 0, size - 1, value);
    cout << setw(80) << (binaryResult != -1 ? "Binary Search: Found at index " + to_string(binaryResult + 1) : "Binary Search: Not found") << endl;

    // =========================
    //       Binary Tree
    // =========================
    cout << setw(80) << "\n=== DEMO: Binary Search Tree ===\n";
    BST<int> bst;
    bst.Insert(1); bst.Insert(8); bst.Insert(7); bst.Insert(5); bst.Insert(12); bst.Insert(9);
    bst.inOrderTraversal(); cout << setw(80) << endl;
    bst.BFS();

    // =========================
    //         AVL Tree
    // =========================
    cout << setw(80) << "\n=== DEMO: AVL Tree ===\n";
    AVL<int> node;
    node.insertNodes(30); node.insertNodes(20); node.insertNodes(13);
    node.insertNodes(18); node.insertNodes(50); node.insertNodes(50);
    node.insertNodes(5);
    node.inOrder();
    cout << setw(80) << "\nAfter Deletion:\n";
    node.deleteNode(50); node.deleteNode(40);
    node.inOrder();

    // =========================
    //          Graph
    // =========================
    cout << setw(80) << "\n=== DEMO: Graph ===\n";
    int n, start, end;
    cout << setw(80) << "Graph size: "; cin >> n;
    Graph<int> g(n);

    for (int i = 0; i < n; i++) {
        cout << setw(80) << "Enter edge " << i + 1 << ": ";
        cin >> start >> end;
        g.addEdge(start, end);
    }

    g.display();
    cout << setw(80) << "Enter BFS start node: ";
    cin >> start;
    if (start < 0 || start >= n) {
        cout << setw(80) << "Invalid. ";

    }
    g.BFS(start);

    return 0;
}
