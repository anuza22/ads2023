#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

long long p = 31;

unordered_set <long long> sub;

long long getHash(string s){
    long long h=0;
    for(long long i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' + 1);
    }
    return h;
}

void hash_code(string s){
    long long h = s.size();
    long long hs = getHash(s);
    long long pm = 1, pg = 1;

    for(long long i=0; i<h-1; i++) pm*=p;

    for(long long i=0; i<h; i++){
        long long pt = pg;
        long long ht = hs;
        sub.insert(ht);
        for(long long j = h-1; j>i; j--){
            ht-=((s[j] - 'a' + 1)*pt);
            pt*=p;
            sub.insert(ht);
        }

        hs = ((hs - pm * (s[i] - 'a' + 1)) * p);
        pg *= p;
    }
}

int main(){
    string s; cin >> s;
    hash_code(s);
    cout << sub.size() << endl;

}