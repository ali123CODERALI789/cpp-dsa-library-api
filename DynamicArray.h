#pragma once
#include <iostream>
#include <iomanip>
#include "Sorting.h"
using namespace std;
template<typename Temp>
class VectorArray {
private:
    Temp* arr;
    int size;
    
public:
    VectorArray() {
        size = 0;
        arr = new Temp[size];
        for(int i=0;i<=size-1;i++)
            arr[i] = 0;
    }
    void show() {
        cout <<"\n" << setw(80);
        for (int i = 0; i <= size-1; i++)
            cout<<arr[i] << " ";
        cout << endl;
    }
    void push_back(Temp newRow) {
        
        Temp* ptr = new Temp[size + 1];
        
        for (int i = 0; i < size; i++) {
            ptr[i] = arr[i];
        }
        ptr[size] = newRow;

        delete[] arr;  //One dynamic array is deleted
        arr = ptr;  //Now there is only one array (which is created abov) instead of 2 arrays since this is referencing/pointing to the new array
        
        size++;
    }
    void pop_back() {
        if (size > 0)
            size--;
        else
            cout << "\n" << setw(80) << "Vector is already empty\n";
    }

    int getsize() {
        return size;
    }
    void resize(int val) {
        if (val < 0) {
            cout <<"\n" << setw(80) << "Invalid size";
            return;
        }
        if (val > size) {
            Temp* ptr = new Temp[val];

            for (int i = 0; i < size; i++)
                ptr[i] = arr[i];
            for (int i = size; i < val; i++) {
                ptr[i] = 0;
            }
            delete[] arr;
            arr = ptr;

            size=val;
        }
        else if (val < size) {
            Temp* ptr = new Temp[val];
            /*while (size != val) {
                remove(size);
            }*/
            for (int i = 0; i < val; i++)
                ptr[i] = arr[i];
            delete[] arr; 
            arr = ptr;
            size = val;

        }
        else if (val == 0) {
            clear(); 
        }
    }
    void erase(int index) {
        if (index < 1 || index > size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return ;
        }
        for (int i=index-1;i<size;i++)
            arr[i] = arr[i+1];
        size--;


        //arr = ptr; size--;
    }
    void erase(int first,int last) {
        if (first >= last || first<1 || last>size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }
        for (int i = first - 1; i < last; i++) {
            erase(first);
        }


        //arr = ptr; size--;
    }
    void clear() {
        int temp = getsize();
        if (temp == 0) {
            cout << "\n" << setw(80) << "Already empty" << endl; return;
        }
        for (int i = 0; i < temp; i++) {
            erase(1);
        }
    }
    
    void insert(Temp val,int index) {
        if (index < 1 || index > size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }

        Temp* ptr = new Temp[size + 1];
        for (int i = 0; i < index-1; i++) {
            ptr[i] = arr[i];
        }

        ptr[index-1] = val;
        for (int i = size ; i > index-1; i--)
            ptr[i] = arr[i - 1];
        delete[] arr;


        arr = ptr; size++;
    }
    void insert(Temp val, int first, int last) {
        if (first>=last ||first<1 ||last>size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }
        for(int i=first-1;i<last;i++)
            insert(val, first);
        
    }void assign(Temp val,int index) {
        if (index < 1 || index > size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }
        arr[index] = val;
    }
    void assign(Temp val, int first,int last) {
        if (first >= last || first<1 || last>size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }
        for (int i = first - 1; i < last; i++)
            assign(val,i);
    }
    Temp& operator[](int index) {
        if (index < 1 || index > size) {
            cout << "\n" << setw(80) << "Invalid index." << endl;
            return;
        }
        return arr[index];
    }


    int find(Temp cal) {
        
        for( int i = 0;i<size;i++)
            if (arr[i] == cal) {
                cout << "\n" << setw(80) << "Found element " << cal << " at index: " << i + 1 << endl;
                return i+1;
            }
        cout << "\n" << setw(80) << "Not found"; return -1;
    }
    ~VectorArray() {
        if (arr)
        delete[] arr;// Once this is deleted, ptr (which was created locally) is also deleted as it references to the newly created pointer
       
    }
};

