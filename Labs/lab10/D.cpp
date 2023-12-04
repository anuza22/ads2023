#include<bits/stdc++.h>
using namespace std;
vector <int> graph[5001];
bool red[5001];
int n, m, q;

void BFS(int v){
    vector<int> distance(n + 1, -1);
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(red[i]){
            distance[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int neighbor : graph[current]){
            if(distance[neighbor] == -1){
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << distance[v] << endl;
}

int main(){
    cin >> n >> m >> q;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while(q--){
        int q1, v;
        cin >> q1 >> v;
        if(q1 == 1){
            red[v] = true;
        }
        else{
            BFS(v);
        }
    }
    return 0;
}