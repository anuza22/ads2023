#include<iostream>
using namespace std;
char arr[100][100];
int n, m;

void DFS(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j] == '0') return;
    arr[i][j] = '0';
    DFS(i+1, j);
    DFS(i-1, j);
    DFS(i, j+1);
    DFS(i, j-1);
}

int main(){
    cin >> n >> m;
    int cnt=0;

    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '1'){
                cnt++;
                DFS(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

0 1 0 1 
0 1 1 0
0 0 0 0

2