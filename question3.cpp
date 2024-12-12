/*
  Name: Travis
  Student ID: 1113545
  Date of Submission: 2024-12-12

  Description:
  Given a connected undirected graph represented by an adjacency list `adj` 
  (a vector of vectors, where each adj[i] represents the vertices adjacent to vertex i),
  perform a Depth First Search (DFS) starting from vertex 0. 
  
  The DFS should follow the order of neighbors as they appear in the adjacency list.

  Steps:
  1. Initialize a visited array to mark visited nodes.
  2. Perform a recursive DFS (or iterative stack-based) starting from node 0.
  3. For each node visited, add it to the DFS traversal list.
  4. Return/print the DFS order.

  Example:
  If adj = [[1, 2],
            [0, 2],
            [0, 1, 3, 4],
            [2],
            [2]]

  The DFS starting from 0 would visit:
    - 0 first
    - Then 1 (first neighbor of 0)
    - Then 2 (first neighbor of 1)
    - Then 3 (first neighbor of 2)
    - Backtrack to 2, then visit 4 (next neighbor of 2)

  DFS order: [0, 1, 2, 3, 4]
*/

#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsOrder) {
    visited[node] = true;
    dfsOrder.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, dfsOrder);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of vertices
    int V; cin >> V;
    vector<vector<int>> adj(V);

    // Reading adjacency list input format:
    // First line: V
    // Next V lines: each line starts with the number of neighbors k, followed by k neighbors.
    for (int i = 0; i < V; i++) {
        int k; cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
        }
    }

    // DFS traversal
    vector<bool> visited(V, false);
    vector<int> dfsOrder;

    // Start DFS from vertex 0
    dfsUtil(0, adj, visited, dfsOrder);

    // Print the DFS order
    cout << "[";
    for (int i = 0; i < (int)dfsOrder.size(); i++) {
        cout << dfsOrder[i];
        if (i < (int)dfsOrder.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

