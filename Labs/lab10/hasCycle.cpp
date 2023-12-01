#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100000];
bool vis[100000];
int cnt=0;

void dfs(int v, int p = -1){
    vis[v] = true;

    for(int i: graph[v]){
        if(!vis[i]){
            dfs(i, v);
        }else if(i!=p){
            cout << "Cycle" << endl;
            return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    
    return 0;
}