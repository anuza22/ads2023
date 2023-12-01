#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, f;
    cin >> n >> f;
    double arr[n], sum=0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    for(int i = sum/f; i<=ceil(sum/n); i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            int a = ceil(arr[j]/i);
            // cout << a << endl;
            cnt+=a;
        }
        if(cnt <= f) {
            // cout << cnt << endl;
            cout << i << endl;
            return 0;
        }

    }
}