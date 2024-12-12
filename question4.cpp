/*
  Name: Travis
  Student ID: 1113545
  Date of Submission: 2024-12-12

  Description:
  Given a weighted, undirected, and connected graph with V vertices and E edges, 
  find the sum of the weights of the edges in its Minimum Spanning Tree (MST).

  We'll use Prim's or Kruskal's algorithm to find the MST weight. 
  For simplicity, let's implement Kruskal's algorithm here, which requires:
   1. Sort all edges by their weight.
   2. Use a Disjoint Set Union (Union-Find) data structure to add edges 
      one by one, if they don't form a cycle.
   3. Keep track of the total weight added until all V-1 edges are chosen.

  Input Format:
   - First line: V E
   - Next E lines: each line has three integers (u v w) representing 
     an edge between u and v with weight w.

  Example (from the image):
   V = 3, E = 3
   0 1 5
   1 2 3
   0 2 1

  MST for this graph is:
   Edges: (0,2) with weight 1, and (1,2) with weight 3
   Total MST weight = 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n,0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findSet(int x) {
        return (parent[x] == x) ? x : (parent[x] = findSet(parent[x]));
    }
    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    UnionFind uf(V);
    int mstWeight = 0;
    int edgesUsed = 0;

    for (auto &edge : edges) {
        if (uf.unionSet(edge.u, edge.v)) {
            mstWeight += edge.w;
            edgesUsed++;
            if (edgesUsed == V - 1) break; 
        }
    }

    cout << mstWeight << "\n";

    return 0;
}

