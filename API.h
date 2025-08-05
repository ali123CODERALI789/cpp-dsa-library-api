#pragma once
#include "crow_all.h"
#include "Math.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "Sorting.h"
#include "Searching.h"
#include "BST.h"
#include "AVL.h"
#include "Graph.h"

void runCrowServer() {
    crow::SimpleApp app;
    Math m;
    Stack<int> s;
    Queue<int> q;
    VectorArray<int> va;
    BST<int> bst;
    AVL<int> avl;

    // ========= Math APIs =========
    CROW_ROUTE(app, "/math/abs/<int>")([&](int x) { return std::to_string(m.Abs(x)); });
    CROW_ROUTE(app, "/math/isprime/<int>")([&](int x) { return std::to_string(m.isPrime(x)); });
    CROW_ROUTE(app, "/math/fact/<int>")([&](int x) { return std::to_string(m.factorial(x)); });
    CROW_ROUTE(app, "/math/reverse/<int>")([&](int x) { return std::to_string(m.ReverseNumber(x)); });
    CROW_ROUTE(app, "/math/gcd/<int>/<int>")([&](int a, int b) { return std::to_string(m.GCD(a, b)); });
    CROW_ROUTE(app, "/math/lcm/<int>/<int>")([&](int a, int b) { return std::to_string(m.LCM(a, b)); });
    CROW_ROUTE(app, "/math/pow/<int>/<int>")([&](int base, int exp) { return std::to_string(m.power(base, exp)); });
    CROW_ROUTE(app, "/math/palindrome/<int>")([&](int x) { return std::to_string(m.isPalindrome(x)); });
    CROW_ROUTE(app, "/math/sumdigits/<int>")([&](int x) { return std::to_string(m.sumOfDigits(x)); });
    CROW_ROUTE(app, "/math/iseven/<int>")([&](int x) { return std::to_string(m.isEven(x)); });

    // ========= Stack APIs =========
    CROW_ROUTE(app, "/stack/push/<int>")([&](int x) { s.push(x); return "Pushed"; });
    CROW_ROUTE(app, "/stack/pop")([&]() { s.pop(); return "Popped"; });
    CROW_ROUTE(app, "/stack/peek")([&]() { return std::to_string(s.peek()); });

    // ========= Queue APIs =========
    CROW_ROUTE(app, "/queue/enqueue/<int>")([&](int x) { q.enqueue(x); return "Enqueued"; });
    CROW_ROUTE(app, "/queue/dequeue")([&]() { q.dequeue(); return "Dequeued"; });
    CROW_ROUTE(app, "/queue/peek")([&]() { return std::to_string(q.peek()); });

    // ========= VectorArray APIs =========
    CROW_ROUTE(app, "/vector/push/<int>")([&](int x) { va.push_back(x); return "Pushed"; });
    CROW_ROUTE(app, "/vector/insert/<int>/<int>")([&](int val, int index) { va.insert(val, index); return "Inserted"; });
    CROW_ROUTE(app, "/vector/erase/<int>")([&](int index) { va.erase(index); return "Erased"; });
    CROW_ROUTE(app, "/vector/clear")([&]() { va.clear(); return "Cleared"; });
    CROW_ROUTE(app, "/vector/resize/<int>")([&](int sz) { va.resize(sz); return "Resized"; });

    // ========= Searching =========
    int arr[] = { 5, 10, 15, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);

    CROW_ROUTE(app, "/search/linear/<int>")([&](int x) {
        int idx = LinearSearch<int>(arr, n, x);
        return (idx == -1 ? "Not found" : "Found at index " + std::to_string(idx));
        });

    CROW_ROUTE(app, "/search/binary/<int>")([&](int x) {
        int idx = BinarySearch<int>(arr, 0, n - 1, x);
        return (idx == -1 ? "Not found" : "Found at index " + std::to_string(idx));
        });

    // ========= BST & AVL =========
    CROW_ROUTE(app, "/bst/insert/<int>")([&](int x) { bst.Insert(x); return "Inserted into BST"; });
    CROW_ROUTE(app, "/avl/insert/<int>")([&](int x) { avl.insertNodes(x); return "Inserted into AVL"; });
    CROW_ROUTE(app, "/avl/delete/<int>")([&](int x) { avl.deleteNode(x); return "Deleted from AVL"; });

    app.port(18080).multithreaded().run();
}
