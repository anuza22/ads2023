#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, k, max=-1;
    cin >> n >> k;
    int l1[n], r1[n], l2[n], r2[n];
    for(int i=0; i<n; i++){
        cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
        if(l1[i]>max){
            max=l1[i];
        }
        if(r1[i]>max){
            max=r1[i];
        }
        if(l2[i]>max){
            max=l2[i];
        }
        if(r2[i]>max){
            max=r2[i];
        }

    }
    int l=0, r=max, t;
    while(l<=r){
        int mid=(l+r)/2;
        int min=0;
        for(int i=0; i<n; i++){
            if(l1[i]<=mid && l2[i]<=mid &&r1[i]<=mid &&r2[i]<=mid){
                min++;
            }
        }
        if(min>=k){
            r=mid-1;
            t=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << t;

    return 0;
}