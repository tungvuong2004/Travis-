/*
  Name: Travis
  Student ID: 1113545
  Date of Submission: 2024-12-12

  Description:
  This program reads an undirected graph specification (number of vertices V and edges E, 
  followed by E pairs representing the edges) and constructs an adjacency list representation 
  of the graph. It then prints out the adjacency list.

  The adjacency list is represented as a vector of vectors, where for each vertex v, we store 
  a list of vertices that are adjacent to v.

  Steps:
  1. Read the number of vertices (V) and edges (E).
  2. Initialize an adjacency list of size V, where each entry is initially empty.
  3. For each edge provided, add the destination to the source vertex's adjacency list 
     and the source to the destination vertex's adjacency list, since the graph is undirected.
  4. Sort each adjacency list to maintain a consistent order if desired (optional but often preferred).
  5. Print the adjacency list.

  Example:
  If V = 5, E = 7 and edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]],
  the adjacency list should look like:
  0: [1,4]
  1: [0,2,3,4]
  2: [1,3]
  3: [1,2,4]
  4: [0,1,3]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of vertices (V) and edges (E)
    int V, E;
    cin >> V >> E;

    // Initialize adjacency list
    vector<vector<int>> adjList(V);

    // Read the edges and populate the adjacency list
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Since this is an undirected graph, add both ways
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort each adjacency list (optional step, but helps maintain a consistent order)
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    // Print the adjacency list
    // Format: print each vertex's adjacency in a single line, e.g.
    // [[neighbors_of_0],[neighbors_of_1],...]
    cout << "[";
    for (int i = 0; i < V; i++) {
        cout << "[";
        for (int j = 0; j < (int)adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j < (int)adjList[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < V - 1) cout << ",";
    }
    cout << "]\n";

    return 0;
}

