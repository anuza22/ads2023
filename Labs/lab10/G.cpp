#include <bits/stdc++.h>
using namespace std;

vector<int> graph[501];
bool visited[501] = {false};
bool in_stack[501] = {false};

bool hasCycle(int v) {
    visited[v] = true;
    in_stack[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            if (hasCycle(u)) {
                return true;
            }
        } else if (in_stack[u]) {
            return true;
        }
    }

    in_stack[v] = false;
    return false;
}

bool isCyclic(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (hasCycle(i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m; 
    cin >> n >> m;

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        edges.emplace_back(x, y);
    }

    for (int i = 0; i < m; i++) {
        fill(begin(visited), end(visited), false);
        fill(begin(in_stack), end(in_stack), false);

        int removed_edge_x = edges[i].first;
        int removed_edge_y = edges[i].second;
        auto it = find(graph[removed_edge_x].begin(), graph[removed_edge_x].end(), removed_edge_y);
        if (it != graph[removed_edge_x].end()) {
            graph[removed_edge_x].erase(it);
        }

        if (!isCyclic(n)) {
            cout << "YES";
            return 0;
        }

        graph[removed_edge_x].push_back(removed_edge_y);
    }

    cout << "NO";
    return 0;
}
