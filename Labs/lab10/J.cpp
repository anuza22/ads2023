#include <bits/stdc++.h>
using namespace std;

long long n, m, a, b, c;
vector<long long> edges[1234567];
long long parent[1234567];
long long counter[1234567];

void bfs(long long x){
    queue<long long> q;
    q.push(x);
    parent[x] = x;
    while(!q.empty()){
        long long cur = q.front(); q.pop();
        for(long long i : edges[cur]){
            if (!parent[i]){
                parent[i] = cur;
                counter[cur]++;
                q.push(i);
            }
        }
    }
}

int main(){

    cin >> n >> m;
    for(long long i = 0; i < m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(long long i = 1; i <= n; i++){
        if (!parent[i]) {
            bfs(i);
        }
    }
    long long ans = 0;
    for(long long i = 1; i <= n; i++){
        if (parent[i] != i){
            if (counter[i] > counter[parent[i]]) {
                ans++;
            }
        }
        else ans++;
    }
    cout << ans;
    return 0;
}