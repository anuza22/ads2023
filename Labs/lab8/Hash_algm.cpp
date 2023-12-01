#include<iostream>
#include<algorithm>
using namespace std;

int p = 31;
long long mod = 1e9 + 7;


int getHash(string s){
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' +1);
    }
    return h;
}

void rk(string s, string t){
    int n = s.size(), m = t.size();
    int h_s = getHash(s.substr(0, m));
    int h_t = getHash(t);
    int pm = 1;

    for(int i=0; i<m-1; i++) pm*=p;

    for(int i=0; i<=n-m; i++){
        if(h_s == h_t){
            cout << i << " ";
        }
        
        if(i<n-m){
            h_s = (h_s - pm * (s[i]-'a'+1)) *p + (s[i+m]-'a'+1);
        }
    }

}

int main(){
    string s, t;
    cin >> s >> t;
    rk(s, t);
    return 0;
}