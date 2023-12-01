#include<iostream>
#include<algorithm>
using namespace std;

bool BinarySearch(int a[], int key, int n){
    int l=0, r=n-1, mid;

    while(l<=r){
        mid = l+(r-l)/2;
        if(a[mid]==key) 
        return true;

        if(a[mid]>key)
        r = mid-1;
        else l = mid+1;
    }
    return false;
}

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n];

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr[i] = a;
    }
    sort(arr, arr+n);

    for(int i=0; i<q; i++){
        int l1, r1, l2, r2, cnt=0;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l2<=r1) l2 = r1+1; 
        while(l1<=r1){
            if(BinarySearch(arr, l1, n)) cnt++;
            l1++;
        }

        while(l2<=r2){
            if(BinarySearch(arr, l2, n)) cnt++;
            l2++;
        }

        cout << cnt << endl;
    }

    
    return 0;
}