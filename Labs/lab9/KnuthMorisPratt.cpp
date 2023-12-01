#include<bits/stdc++.h>
using namespace std;

void prefix(string s, vector<int>&p){
    int n = s.size();
    p[0] = 0;

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
    // for(int k=0; k<n; k++){
    //     cout << p[k] << " ";
    // }
}

void KMP(string s, string t){
    int s_siz = s.size(), t_siz = t.size();
    vector<int> p(t_siz, 0);
    prefix(t, p);
    int i=0, j=0;
    while(i<s_siz){
        if(s[i] == t[j]){
            i++; j++;
        }else if(j!=0){
            j = p[j-1];
        }else{
            i++;
        }
        if(j == t_siz){
            cout << i-j << " ";
            j = p[j-1];
        }
    }
}

int main(){
    string s, t; 
    cin >> s >> t;
    KMP(s, t);

    return 0;
}