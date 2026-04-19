
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Edge structure
struct Edge {
    int src, dest, weight;
};

// Disjoint Set (Union-Find)
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by Rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Comparator for sorting edges
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(V);
    vector<Edge> result;
    int totalWeight = 0;

    for (auto edge : edges) {
        int x = ds.find(edge.src);
        int y = ds.find(edge.dest);

        if (x != y) {
            result.push_back(edge);
            totalWeight += edge.weight;
            ds.unite(x, y);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : result) {
        cout << edge.src << " -- "
             << edge.dest << " == "
             << edge.weight << "\n";
    }

    cout << "Total Weight of MST = " << totalWeight << endl;
}

int main() {
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V);

    return 0;
}