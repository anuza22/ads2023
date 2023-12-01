#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][n];
    vector <int> v[n];
    queue<int> q;
    unordered_map <int, int> edge, visited;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                v[i].push_back(j);
            }
        }
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    q.push(v1);
    edge[v1] = 0;

    while(!q.empty()){
        int c = q.front();
        visited[c] = 1;
        q.pop();

        for(auto i: v[c]){
            if(!visited[i]){
                q.push(i);
                edge[i] = edge[c]+1;
                if(i == v2){
                    cout << edge[i] << endl;
                    return 0;
                }

            }
        }
    }

    cout << -1 << endl;
    return 0;
}