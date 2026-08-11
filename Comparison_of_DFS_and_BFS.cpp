/*
=========================================================
Practical 8
Title : Comparison of DFS and BFS
Subject : Design and Analysis of Algorithms (DAA)
=========================================================
*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)
void DFS(int v, const vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[v] = true;
    cout << v << " ";

    // Visit every unvisited adjacent vertex
    for (int next : adj[v])
    {
        if (!visited[next])
            DFS(next, adj, visited);
    }
}

// BFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)
void BFS(int start, const vector<vector<int>>& adj)
{
    int V = adj.size();

    vector<bool> visited(V, false);

    // Manual queue instead of <queue>
    vector<int> q(V);
    int front = 0;
    int rear = 0;

    visited[start] = true;
    q[rear++] = start;

    while (front < rear)
    {
        int v = q[front++];
        cout << v << " ";

        // Visit all unvisited adjacent vertices
        for (int next : adj[v])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q[rear++] = next;
            }
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Adjacency List
    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    // ---------------- DFS ----------------

    vector<bool> visitedDFS(V, false);

    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    DFS(start, adj, visitedDFS);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(endDFS - startDFS).count();

    // ---------------- BFS ----------------

    auto startBFS = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    BFS(start, adj);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(endBFS - startBFS).count();

    // ---------------- OUTPUT ----------------

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime << " ns";
    cout << "\nBFS: " << bfsTime << " ns";

    return 0;
}
