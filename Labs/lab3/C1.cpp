#include<bits/stdc++.h>
using namespace std;

// не работает

int binarySearch(int arr[], int leftnum, int rightnum, int size) {
    int left = 0;
    int right = size-1;
    int leftIndex = -1;
    int rightIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= leftnum) {
            leftIndex = mid;
            right = mid - 1; // Continue searching on the left side
        } else if (arr[mid] <= rightnum) {
            rightIndex = mid;
            left = mid + 1; // Continue searching on the right side
        } else if (arr[mid] < leftnum) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return (rightIndex - leftIndex) + 1;
    
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
        cout << binarySearch(arr, l1, r1, n) + binarySearch(arr, l2, r2, n) << endl;
    }

    
    return 0;
}