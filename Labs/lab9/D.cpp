#include<bits/stdc++.h>

using namespace std;

int prefix(string s){
    int n = s.size();
    vector <int> p(n, 0);

    for(int i=1; i<n; i++){
        int j=p[i-1];

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
    int n; 
    string s;
    cin >> s;
    KMP("abababbba", s);
    // cin >> s;
    // cin >> n;

    // for(int i=0; i<n; i++){
    //     string a; cin >> a;


    // }
    return 0;
}