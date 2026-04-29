#include <iostream>
using namespace std;

typedef pair<int, int> pii; 
// {distance, vertex}

void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<pii>> adj(V);

    // SAME INPUT AS BEFORE (Undirected Graph)

    adj[0].push_back({10,1});
    adj[1].push_back({10,0});

    adj[0].push_back({6,2});
    adj[2].push_back({6,0});

    adj[0].push_back({5,3});
    adj[3].push_back({5,0});

    adj[1].push_back({15,3});
    adj[3].push_back({15,1});

    adj[2].push_back({4,3});
    adj[3].push_back({4,2});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}