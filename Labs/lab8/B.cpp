#include<iostream>
#include<algorithm>
using namespace std;

int p = 31;

int getHash(string s){
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' +1);
    }
    return h;
}

int hash_code(string s1, string s2, string k){
    int s1_s = s1.size(), s2_s = s2.size(), k_s = k.size();
    int h_s1 = getHash(s1.substr(0, k_s));
    int h_s2 = getHash(s2.substr(0, k_s));
    int h_k = getHash(k);
    int pm = 1, cnt=0;

    for(int i=0; i<k_s-1; i++) pm*=p;

    for(int i=0; i<=s1_s-k_s && i<=s2_s-k_s; i++){
        if(h_s1 == h_k && h_s2==h_k){
            cnt++;
        }
        if(i<s1_s-k_s && i<s2_s-k_s){
            h_s1 = (h_s1 - pm * (s1[i]-'a'+1)) *p + (s1[i+k_s]-'a'+1);
            h_s2 = (h_s2 - pm * (s2[i]-'a'+1)) *p + (s2[i+k_s]-'a'+1);
        }
    }

    return cnt;
}

int main(){
    string s1, s2, k;
    cin >> s1 >> s2 >> k;

    cout << hash_code(s1, s2, k);
    return 0;
}