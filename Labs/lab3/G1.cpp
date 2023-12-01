#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int mid, int pos){
    int total = 0;

    for(int i=0; i<n; i++){
        total+=(arr[i] + mid - 1)/mid;
    }

    if(total <= pos) return true;
    return false;
    
}

int main(){
    int numOFChildren, pos, max=-1;
    cin >> numOFChildren >> pos;
    int children[numOFChildren];

    for(int i=0; i<numOFChildren; i++){
        cin >> children[i];
        if(children[i] > max) max = children[i];
    }

    int l = 1, r = max, mid, res;

    while(l<=r){
        mid = l+(r-l)/2;

        if(check(children, numOFChildren, mid, pos)){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 

    cout << res << endl;
    return 0;
}