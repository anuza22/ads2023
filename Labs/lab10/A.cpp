#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int n, m, cnt =0;

// does not work

void DFS(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j] !=1) return;

    arr[i][j] = 2;
    cnt++;

    DFS(i+1, j);
    DFS(i-1, j);
    DFS(i, j+1);
    DFS(i, j-1);
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 2)
            DFS(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}