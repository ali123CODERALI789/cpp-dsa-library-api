#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"
using namespace std;

template <typename Temp,int size>
void show(Temp (&arr)[size])
{
    cout <<"\n" << setw(80);
    for (int j = 0; j < size; j++)
    {
        cout<< arr[j] <<" ";
    }
    cout << endl;
}

template <typename Temp, int size>
void BubbleSort(Temp (&arr)[size])
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            bool check = false;
            if (check)
            {
                return;
            }
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                check = true;
            }
            
        }
    }
}
template <typename Temp, int size>
void SelectionSort(Temp (&arr)[size])
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int maxindex = i;
        for (j = i-1;j<size;j++)
        {
            if (arr[maxindex] > arr[j])
            {
                maxindex = j;
            }
        }
        if (arr[maxindex] < arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[maxindex];
            arr[maxindex] = temp;
        }
    }
}
template <typename Temp, int size>
void sort(Temp (&arr)[size])
{
    int current, previous;
    for (int i = 0; i < size; i++)
    {
        current = arr[i];
        for(previous = i - 1;(previous >= 0 && arr[previous] > current);previous--){ 
            arr[previous + 1] = arr[previous];
        
        }
        arr[previous + 1] = current;

    }
}



