#include<iostream>
using namespace std;

int binar(int arr[], int key, int n){
    int r = n - 1;
    int l = 0;

    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == key ) return mid;
        else if(arr[mid] < key){
            l = mid+1;
        }else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    int n, m, sum =0;
    cin >> n >> m;
    int p[n];

    for(int i=0; i<n; i++){
        int a; cin >> a;
        sum+=a;
        p[i] = sum;
    }

    for(int i=0; i<m; i++){
        int t; cin >> t;
        cout << binar(p, t, n) + 1<< endl;
        
    }
    return 0;

}