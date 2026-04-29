#include <iostream>
using namespace std;

// Step 1: DFS to fill stack
void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, st);
        }
    }

    st.push(node);
}

// Step 2: DFS on reversed graph
void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, revAdj, visited);
        }
    }
}

void kosaraju(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    // Step 1: Fill stack
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Reverse graph
    vector<vector<int>> revAdj(n);
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            revAdj[v].push_back(i);
        }
    }

    // Step 3: DFS in stack order
    fill(visited.begin(), visited.end(), false);

    cout << "Strongly Connected Components:\n";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            dfs2(node, revAdj, visited);
            cout << endl;
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {2};
    adj[2] = {1};
    adj[1] = {0};
    adj[0].push_back(3);
    adj[3] = {4};

    kosaraju(n, adj);

    return 0;
}