#include<bits/stdc++.h>
using namespace std;

// проблема: считает два раза print(len("nugman"*7))gg

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
    int k; cin >> k;

    for(int i=0; i<k; i++){
        string t; int c;
        cin >> t >> c;
        int cnt = prefix(t);
        cout << (c*t.size() - (c-1)*cnt) << endl;
    }
  
}