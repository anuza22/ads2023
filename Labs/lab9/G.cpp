#include<bits/stdc++.h>

using namespace std;

long long prefix(string s){
    long long n = s.size();
    vector <long long> p(n, 0);

    for(long long i=1; i<n; i++){
        long long j=p[i-1];
        
        while(j>0 && s[i] != s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j]){
            p[i] = j+1;
        } else{
            p[i] = j;
        } 
    }
    return p[n-1];
}

int main(){
    string s; cin >> s;
    int cnt = prefix(s);
    cout << s.size() -  cnt << endl;
}