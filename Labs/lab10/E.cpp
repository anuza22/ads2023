#include<iostream>
using namespace std;

int main(){
    long long n, q;
    cin >> n >> q;
    long long arr[n][n];
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(long long k=0; k<q; k++){
        long long el1, el2, el3;
        cin >> el1 >> el2 >> el3;

        if(arr[el1-1][el2-1] && arr[el2-1][el3-1] && arr[el1-1][el3-1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;

}