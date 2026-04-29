#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

const int V = 6;

bool dfs(int s, int t, vector<vector<int>>& rGraph, vector<int>& parent) {
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty()) {
        int u = st.top(); st.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return visited[t];
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while (dfs(s, t, rGraph, parent)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Sample graph for Ford-Fulkerson algorithm
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5
    // with capacities
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    cout << "Maximum flow from source " << source << " to sink " << sink << " is: "
         << fordFulkerson(graph, source, sink) << endl;

    return 0;
}