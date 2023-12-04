#include<bits/stdc++.h>
using namespace std;

int field[1000][1000];
int n, m;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int i, int j, queue<pair<int, int>>& q) {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // четыри стороны

    for (auto& dir : directions) {
        int ni = i + dir[0];
        int nj = j + dir[1];

        if (isValid(ni, nj) && field[ni][nj] == 1) {
            field[ni][nj] = 2;
            q.push(make_pair(ni, nj));
        }
    }
}

int findMinutes() {
    queue<pair<int, int>> q;

    bool hasMario = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 2) {
                hasMario = true;
                q.push(make_pair(i, j));
            }
        }
    }
    if (!hasMario) {
        return 0;  
    }

    int minutes = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();

            int ci = curr.first;
            int cj = curr.second;

            bfs(ci, cj, q);
        }

        minutes++;
    }

    return minutes - 1; 
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    int minutes = findMinutes();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << minutes << endl;

    return 0;
}

