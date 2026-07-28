/*
=========================================================
Practical 2
Title : Comparison of Linear Search and Binary Search
Subject : Design and Analysis of Algorithms (DAA)
Language : C++
=========================================================
*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(const vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == key)
            return i;

    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n = 100000;
    vector<int> arr(n);

    // Create Sorted Array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    auto start = high_resolution_clock::now();
    int index = linearSearch(arr, key);
    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search\n";

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Binary Search
    start = high_resolution_clock::now();
    index = binarySearch(arr, key);
    stop = high_resolution_clock::now();

    cout << "\nBinary Search\n";

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
