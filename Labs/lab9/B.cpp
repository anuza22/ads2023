#include<bits/stdc++.h>
using namespace std;

void prefix(string s, vector<long long> &p){
    long long n = s.size();
    p[0] = 0;

    for(long long i = 1; i<n; i++){
        long long j = p[i-1];

        while(j>0 && s[i] != s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j]){
            p[i] = j+1;
        }else {
            p[i] = j;
        }
    }
}

long long KMP(string s, string t){
    long long s_siz = s.size(), t_siz = t.size(), cnt=0;
    vector<long long> p(t_siz, 0);
    prefix(t, p);
    long long i=0, j=0;
    while(i<s_siz){
        if(s[i] == t[j]){
            i++; j++;
        }else if(j!=0){
            j = p[j-1];
        }else{
            i++;
        }
        if(j == t_siz){
            cnt++;
            j = p[j-1];
        }
    }
   return cnt;
}

int main(){
    string s, t;
    long long k;
    cin >> t >> k;
    cin >> s;

    // cout << KMP(s, t) << endl;

    if(k <= KMP(s, t)) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}