/*
=========================================================
Practical 3
Title : Comparison of Iterative and Recursive Factorial
Subject : Design and Analysis of Algorithms (DAA)
Language : C++
=========================================================
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Iterative Factorial
unsigned long long iterative(int n)
{
    unsigned long long fact = 1;

    while (n > 1)
        fact *= n--;

    return fact;
}

// Recursive Factorial
unsigned long long recursive(int n)
{
    return (n <= 1) ? 1 : n * recursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a non-negative integer (e.g., 20): ";
    cin >> n;

    // Iterative Method
    auto start = high_resolution_clock::now();
    unsigned long long iFact = iterative(n);
    auto stop = high_resolution_clock::now();

    auto iTime = duration_cast<nanoseconds>(stop - start).count();

    // Recursive Method
    start = high_resolution_clock::now();
    unsigned long long rFact = recursive(n);
    stop = high_resolution_clock::now();

    auto rTime = duration_cast<nanoseconds>(stop - start).count();

    // Output
    cout << "\n--- Results for " << n << "! ---" << endl;
    cout << "Iterative Result : " << iFact << endl;
    cout << "Iterative Time   : " << iTime << " ns" << endl;
    cout << "-------------------------------" << endl;
    cout << "Recursive Result : " << rFact << endl;
    cout << "Recursive Time   : " << rTime << " ns" << endl;

    return 0;
}
