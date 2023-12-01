#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int prime = 11;
long long mod = 1e9 + 7;

// rolling hash
// unordered_set = O(n) --> const
// set = O(n^2)

string getHash(string s){
    long long h = 0;
    for(long long i=s.size()-1; i>=0; i--){
        h = (h*prime%mod + (s[i]-47))%mod;
    }
    return to_string(h);
}

int main(){
    long long n, cnt=0; cin >> n;

    unordered_set <string> str;
    pair<string, string> hash[2*n];


    for(long long i=0; i<2*n; i++){
        string a; cin >> a;
        hash[i].first = getHash(a);
        hash[i].second = a;
        str.insert(a);
    }

    for(long long i = 0; i<2*n; i++){
        unordered_set <string> :: iterator it = str.find(hash[i].first);
        if(it!=str.end()){
            cout << "Hash of string \"" << hash[i].second <<"\" is " << hash[i].first << endl;
            cnt++;
            if(cnt==n) break;
        }


    }


    return 0;
}