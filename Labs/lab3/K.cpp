#include<bits/stdc++.h>
using namespace std;

int SubArrayMinLen(int a[], int target, int n){
    int l = 0;
    int sum = 0;
    int minVal = 1000000;

    for(int i = 0; i<n; i++){
        sum+=a[i];

        while(sum>=target){
            minVal = min(minVal, i+1-l);
            sum-=a[l];
            l++;
        }
    }
    return minVal;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << SubArrayMinLen(arr, k, n) << endl;
    return 0;
}