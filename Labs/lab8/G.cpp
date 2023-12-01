#include<iostream>
#include<algorithm>
using namespace std;

int p = 31;

string getSubstr(string s, int a, int b){
    string k = "";
    for(int i = a-1; i<b; i++){
        k+=s[i];
    }
    return k;
}

int getHash(string s){
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' +1);
    }
    return h;
}

int hash_code(string s, string t){
    int n = s.size(), m = t.size();
    int h_s = getHash(s.substr(0, m));
    int h_t = getHash(t);
    int pm = 1, cnt=0;

    for(int i=0; i<m-1; i++) pm*=p;

    for(int i=0; i<=n-m; i++){
        if(h_s == h_t){
            cnt++;
        }

        if(i<n-m){
            h_s = (h_s - pm * (s[i]-'a'+1)) *p + (s[i+m]-'a'+1);
        }
    }

    return cnt;
}

int main(){
    string word; cin >> word;
    int n; cin >> n;
    pair <int, int> p;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        cout << hash_code(word, getSubstr(word, a, b)) << endl;
    }

    return 0;
}