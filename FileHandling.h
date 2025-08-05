#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
class FileHandling
{
protected:
    int count;
    string names[20];
    int scores[20];
public:
    FileHandling()
    {
        count = 0;
        for (int i = 0; i < 20; i++) {
            scores[i] = 0; names[i] = "";
        }
    }



    void SelectionSort(int* arr, int size, string* n)
    {
        for (int i = 0; i < size; i++)
        {
            int temp = i;
            for (int j = i; j < size; j++)
            {
                if (arr[temp] < arr[j])
                    temp = j;
            }
            if (arr[temp] > arr[i])
            {
                swap(arr[temp], arr[i]);
                swap(n[temp], n[i]);
            }
        }
    }

    void ReadFile(string filename)
    {
        ifstream fs(filename); // correct mode for reading

        if (!fs.is_open())
        {
            cerr << setw(80) << "Error opening file for reading.\n";
            return;
        }

        string name;
        int score;
        int rank = 1;

        cout << "\n\t\t" << setw(80)<<"TOP SCORES:\n";
        cout << "\t\t" << setw(80) <<"------------------\n";
        while (fs >> name >> score && rank <= 10) {
            cout << "\t\t" << setw(80) << rank << ". " << name << " - " << score << endl;
            rank++;
        }


        fs.close();
       
    }


    void WriteFile(string filename, int currentScore, const string& currentName) {
        ifstream file(filename);
        int total = 0;

        if (file.is_open()) {
            while (file >> names[total] >> scores[total] && total < 19) {
                total++;
            }
            file.close();
        }

        // Add new entry
        names[total] = currentName;
        scores[total] = currentScore;
        total++;

        if (total > 10) total = 10;

        SelectionSort(scores, total, names);

        ofstream fs(filename, ios::trunc);
        if (!fs.is_open()) {
            cerr << setw(80) << "Error opening file for writing.\n";
            return;
        }

        for (int i = 0; i < total; i++) {
            fs << names[i] << " " << scores[i] << endl;
        }

        fs.close();
    }

    ~FileHandling()
    {

    }
};