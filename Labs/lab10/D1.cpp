#include <bits/stdc++.h>
using namespace std;

vector<int> graph[5001];
bool red[5001];

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (red[i]) {
            vector<int> dist(n + 1, -1);
            queue<int> bfs_queue;
            bfs_queue.push(i);
            dist[i] = 0;

            while (!bfs_queue.empty()) {
                int current = bfs_queue.front();
                bfs_queue.pop();

                for (int neighbor : graph[current]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[current] + 1;
                        bfs_queue.push(neighbor);
                    }
                }
            }

            for (int j = 1; j <= n; j++) {
                if (dist[j] != -1 && (distance[j][i] == -1 || dist[j] < distance[j][i])) {
                    distance[j][i] = dist[j];
                }
            }
        }
    }

    while (q--) {
        int q1, v;
        cin >> q1 >> v;

        if (q1 == 1) {
            red[v] = true;
        } else if (q1 == 2) {
            int min_distance = -1;
            for (int i = 1; i <= n; i++) {
                if (red[i] && (min_distance == -1 || distance[v][i] < min_distance)) {
                    min_distance = distance[v][i];
                }
            }
            cout << min_distance << endl;
        }
    }

    return 0;
}
