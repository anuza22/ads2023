#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long p = 31;

int getHash(string s){
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' +1);
    }
    return h;
}

void hash_code(string s, string t, vector <bool> &a){
    int n = s.size(), m = t.size();
    int h_s = getHash(s.substr(0, m));
    int h_t = getHash(t);
    int pm = 1;

    for(int i=0; i<m-1; i++) pm*=p;

    for(int i=0; i<=n-m; i++){
        if(h_s == h_t){
            int n = t.size();
            int j=i;
            while(n--){
                a[j] = true;
                j++;
            }
        }

        if(i<n-m){
            h_s = (h_s - pm * (s[i]-'a'+1)) *p + (s[i+m]-'a'+1);
        }
    }

}



int main(){
    string word;
    cin >> word;
    int n; cin >> n;
    vector <bool> ch(word.size(), false);
    for(int i=0; i<n; i++){
        string s; cin >> s;
        hash_code(word, s, ch);
    }

    for(int i=0; i<word.size(); i++){
        if(!ch[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}