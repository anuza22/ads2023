#include<iostream>
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
    int n, k;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> k;

    if(BinarySearch(arr, k, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}