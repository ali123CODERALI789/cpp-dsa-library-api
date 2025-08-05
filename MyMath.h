#pragma once
#include <iostream>
#include <cmath>
#include "Node.h"
using namespace std;
class Math {
public:
    Math() {}

    float Abs(float val) {
        if (val <= 0) {
            val *= -1;
        }
        return val;
    }

    // Function to check divisibility of number from 2 to num-1
    bool isPrime(int num)
    {
        if (num == 1)
            return false;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return false; // Not prime
            }
        }
        return true; // Prime
    }
    // Recursive function to return factorial of number
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return n;

        return factorial(n - 1) * n;
    }

    // Logic to reverse digits using modulo and division
    int ReverseNumber(int n)
    {
        int rev = 0;
        do
        {
            int store = n % 10;       // Get last digit
            rev = (rev + store) * 10; // Add digit and shift left
            n /= 10;                  // Remove last digit
        } while (n != 0);

        return rev / 10; // Adjust for extra multiplication
    }
    float pi = 3.14159;
    float degree = pi / 180.0;
    float radian = 180.0 / pi;
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);

    }

    int LCM(int a, int b)
    {

        return (a * b) / GCD(a, b);

    }

    int power(int base, int exp) {
        int result = 1, i = 0;
        do {
            result *= base;
            i++;
        } while (i < exp);
        return result;

    }
    bool isPalindrome(int n) {
        int pal = 0,original=n;
        do {
            int div = n % 10;
            pal = (pal * 10) + div;
            n /= 10;
        } while (n != 0);
        return pal==original;
    }
    int sumOfDigits(int n) {
        int pal = 0, original = n;
        do {
            pal+=  (n % 10);
            n /= 10;
        } while (n != 0);
        return pal;
    }
    bool isEven(int n) {
        return n % 2 == 0;
    }
} ;