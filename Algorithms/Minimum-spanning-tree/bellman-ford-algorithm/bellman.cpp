#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {1, 0, 10},

        {0, 2, 6},
        {2, 0, 6},

        {0, 3, 5},
        {3, 0, 5},

        {1, 3, 15},
        {3, 1, 15},

        {2, 3, 4},
        {3, 2, 4}
    };

    int E = edges.size();
    int source = 0;

    bellmanFord(V, E, edges, source);

    return 0;
}