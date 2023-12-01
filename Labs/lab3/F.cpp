#include<bits/stdc++.h>
using namespace std;



int BinarySeach(int arr[], int key, int n){
    int l = 0, r = n-1;

    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] >= key && arr[mid-1] <= key) return mid;
        else if( arr[mid] < key){
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
}

// 1 2 2 6 7 8 9

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr[i]  = a;
    }

    sort(arr, arr+n);
    int p; cin >> p;
    int brr[p];
    int cnt, sum;

    for(int i=0; i<p; i++){
        int b; cin >> b;
        cnt = 0; sum=0;
        for(int j = 0; j<BinarySeach(arr, b, n); j++){
            sum+=arr[j];
            cnt++;
        } 
        cout << cnt << " " << sum << endl;
    }



    return 0;
}