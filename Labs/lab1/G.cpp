#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int a){
    if(a==1) return false;

    for(int i=2; i<=a/i; i++){
        if(a%i==0) return false;
    }
    return true;
}

int main(){
    vector <int> v, s;
    int n;
    cin >> n;
    v.push_back(1);
    for(int i =2; i<=100000; i++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }

    for(int i = 2; i<v.size(); i++){
        if(isPrime(i)){
            s.push_back(v[i]);
        }
    }

    cout << s[n-1] << endl;
    return 0;
}