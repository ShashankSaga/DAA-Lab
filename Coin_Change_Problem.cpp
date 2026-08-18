/*
=========================================================
Practical : Coin Change Problem
Title     : Minimum Coin Change using Dynamic Programming
Subject   : Design and Analysis of Algorithms (DAA)
=========================================================
*/

#include <iostream>
using namespace std;

int main()
{
    int n, amount;

    // Input number of different coin types
    cout << "Enter number of coins: ";
    cin >> n;

    int coins[100];

    // Input coin denominations
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // Input target amount
    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum number of coins needed to make amount i
    int dp[1001];

    // parent[i] = coin used to get the best answer for amount i
    int parent[1001];

    // Base case:
    // 0 coins are needed to make amount 0
    dp[0] = 0;

    // Calculate answer for every amount from 1 to target
    for (int i = 1; i <= amount; i++)
    {
        // Assume amount i cannot be made initially
        dp[i] = amount + 1;

        // Try every available coin
        for (int j = 0; j < n; j++)
        {
            // Coin can be used only if coin <= current amount
            if (coins[j] <= i)
            {
                // Check if using this coin gives fewer coins
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    // Update minimum number of coins
                    dp[i] = dp[i - coins[j]] + 1;

                    // Store the coin used
                    parent[i] = coins[j];
                }
            }
        }
    }

    // If target amount cannot be formed
    if (dp[amount] == amount + 1)
    {
        cout << "\nNot possible";
        return 0;
    }

    // Display minimum number of coins
    cout << "\nMinimum coins = " << dp[amount];

    // Display which coins were selected
    cout << "\nCoins used = ";

    int current = amount;

    // Trace back from target amount to 0
    while (current > 0)
    {
        // Print the coin selected for current amount
        cout << parent[current] << " ";

        // Go to the remaining amount
        current -= parent[current];
    }

    return 0;
}
