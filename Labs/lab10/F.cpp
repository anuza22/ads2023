#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adjList;
vector<bool> vis;

void dfs(int v, unordered_set<int>& component) {
    vis[v] = true;
    component.insert(v);

    for (int u : adjList[v]) {
        if (!vis[u]) {
            dfs(u, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    vector<unordered_set<int>> comp;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            unordered_set<int> component;
            dfs(i, component);
            comp.push_back(component);
        }
    }

    for (int i = 0; i < comp.size(); ++i) {
    const unordered_set<int>& component = comp[i];
    if (component.count(s) && component.count(f)) {
        cout << "YES\n";
        return 0;
    }
}


    cout << "NO\n";

    return 0;
}

