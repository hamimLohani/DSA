#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; 
// {weight, vertex}

void prim(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    int totalWeight = 0;

    // Start from vertex 0
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += weight;

        for (auto edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i 
             << " == " << key[i] << "\n";
    }

    cout << "Total Weight = " << totalWeight << endl;
}

int main() {
    int V = 4;
    vector<vector<pii>> adj(V);

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

    prim(V, adj);

    return 0;
}