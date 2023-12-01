#include<bits/stdc++.h>
using namespace std;

char choosePivot(char *a, int left, int right){
    return a[(left+right)/2]; 
}
int partition(char *a, int left, int right){
    char pivot = choosePivot(a, left, right);

    while(left <= right){
        while(a[left] < pivot){
            left++;}
        while(a[right] > pivot){
            right--;}
        if(left <= right){
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(char *a, int left, int right){
    if (left >= right) {
        return;
    }
    if(left < right){
        int pivotindex = partition(a, left, right);
        quicksort(a, left, pivotindex-1);
        quicksort(a, pivotindex, right);
    }
}

int main(){
    string s; cin >> s;
    char a[s.size()];
    for(int i=0; i<s.length(); i++){
        a[i] = s[i];
    }
    quicksort(a, 0, s.size()-1);
    for(int i=0; i<s.length(); i++){
        cout << a[i];
    }
    return 0;
}