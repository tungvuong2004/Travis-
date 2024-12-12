/*
  Name: Travis
  Student ID: 1113545
  Date of Submission: 2024-12-12

  Description:
  Given a connected undirected graph represented by an adjacency list `adj`, 
  perform a Breadth First Search (BFS) traversal starting from vertex 0.
  
  The adjacency list `adj` is given as a vector of vectors, where each adj[i] 
  represents the list of vertices adjacent to vertex i. We will traverse the graph 
  in BFS order, visiting neighbors in the same order they appear in the adjacency list.

  Steps:
  1. Create a queue for BFS and a visited vector to keep track of visited vertices.
  2. Start by pushing vertex 0 into the queue and marking it as visited.
  3. While the queue is not empty:
       - Pop the front vertex from the queue (current vertex).
       - Add it to the BFS order result.
       - Enqueue all its non-visited neighbors (in the order they appear in the adjacency list).
  4. Return the BFS order as a list of vertices.

  Example:
  Input: adj = [[2,3,1], [0], [0,4], [0], [2]]
  Explanation:
   - Start at 0 -> Visit 0
     Neighbors of 0: 2, 3, 1 in that order
   - Visit 2 next (first neighbor of 0)
     Neighbors of 2: 0,4 but 0 is visited, so only enqueue 4
   - Visit 3 next (next neighbor of 0)
     Neighbors of 3: 0 is visited, so do nothing
   - Visit 1 next (next neighbor of 0)
     Neighbors of 1: 0 is visited, so do nothing
   - Visit 4 next (neighbor of 2)
   
  BFS order: [0, 2, 3, 1, 4]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of vertices
    int V; cin >> V;
    // Read the adjacency list
    // We'll assume the input format:
    // First line: V
    // Next V lines: each line is the adjacency list for that vertex
    vector<vector<int>> adj(V);
    for (int i = 0; i < V; i++) {
        // Read the adjacency list for vertex i
        // Input format not clearly stated: Let's assume:
        // First, read the number of neighbors for i, then read those neighbors
        int k; cin >> k; 
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
        }
    }

    // BFS traversal from vertex 0
    vector<int> bfsOrder;
    vector<bool> visited(V, false);
    queue<int> q;

    // Start BFS from vertex 0
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bfsOrder.push_back(cur);

        // Enqueue all non-visited neighbors
        for (int neighbor : adj[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Print the BFS order
    cout << "[";
    for (int i = 0; i < (int)bfsOrder.size(); i++) {
        cout << bfsOrder[i];
        if (i < (int)bfsOrder.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

