/*
=========================================================
Practical 3
Title : Comparison of Max Heap Sort and Min Heap Sort
Subject : Design and Analysis of Algorithms (DAA)
=========================================================
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// Max Heap
void maxHeapify(vector<int>& a, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void maxHeapSort(vector<int>& a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// Min Heap
void minHeapify(vector<int>& a, int n, int i)
{
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void minHeapSort(vector<int>& a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    srand(time(0));

    for (int i = 0; i < n; i++)
        original[i] = rand() % 100000;

    vector<int> maxArr = original;
    vector<int> minArr = original;

    auto start = high_resolution_clock::now();
    maxHeapSort(maxArr);
    auto stop = high_resolution_clock::now();

    auto maxNano = duration_cast<nanoseconds>(stop - start).count();
    auto maxMicro = duration_cast<microseconds>(stop - start).count();

    start = high_resolution_clock::now();
    minHeapSort(minArr);
    stop = high_resolution_clock::now();

    auto minNano = duration_cast<nanoseconds>(stop - start).count();
    auto minMicro = duration_cast<microseconds>(stop - start).count();

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << maxNano << " ns\n";
    cout << "Microseconds : " << maxMicro << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << minNano << " ns\n";
    cout << "Microseconds : " << minMicro << " us\n";

    return 0;
}
