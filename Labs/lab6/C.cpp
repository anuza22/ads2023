#include<iostream>
#include<algorithm>
#include<map>
#include <climits>
using namespace std;

int partition(int a[], int left, int right, int pivot){
    while(left<=right){
        while(a[left] < pivot) left++;

        while(pivot < a[right]) right--;

        if(left<=right){
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int a[], int left, int right){
    if(left>=right) return;

    int pivot = a[(left+right)/2];
    int index = partition(a, left, right, pivot);
    quicksort(a, left, index-1);
    quicksort(a, index, right);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    map<pair<int, int>, int> m;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, n-1);
    int diff = INT_MAX;

    for(int i = 1;i < n; i++){
        diff = min(diff, a[i]-a[i-1]);
        m[{a[i],a[i-1]}] = a[i]-a[i-1];
    }

    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second == diff){
            cout << it->first.second << " " << it->first.first << " ";
        }
    }

    return 0;
}