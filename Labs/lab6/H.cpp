#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    char arr[n], k;
    
    for(int i=0; i<n; i++) 
        cin >> arr[i];

    cin >> k;

    for(int i=0; i<n; i++){
        if(arr[i] > k) {
            cout << arr[i] << endl;
            return 0;
        }
    }

    cout << arr[0] << endl;
    return 0;
}