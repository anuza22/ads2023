#include<bits/stdc++.h>
using namespace std;

bool canSplit(long long arr[], int n, long long big, int k){
    long long subArray = 0;
    long long current = 0;
    // жадный алгоритм

    for(int i=0; i<n; i++){
        current+=arr[i];

        if(current > big){
            subArray++;
            current = arr[i];
        }
    }

    return subArray+1 <=k;

}

long long minPossMaxNum(long long arr[], int n, int k, long long max, long long sum){
    long long l = max, r = sum, mid;
    long long res = r;

    while(l<=r){
        mid = l +(r-l)/2;

        if(canSplit(arr,n, mid, k)){
            res = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }

    }

    return res;
}

int main(){

    int n, k;
    cin >> n >> k;
    long long  arr[n], sum = 0, max = 0;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] > max) max = arr[i];
        sum += arr[i];
    }

    cout << minPossMaxNum(arr, n, k, max, sum) << endl;





    return 0;
}