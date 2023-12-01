#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

// run time error

long long numberOfDistSubstr(string s, unordered_set<string> &a){
    for(long long i=0; i<s.size(); i++){
        string sub = "";
        for(long long j=i; j<s.size(); j++){
            sub+=s[j];
            a.insert(sub);
        }
    }
    return a.size();
}

int main(){
    string s; cin >> s;
    unordered_set<string> number;

    cout << numberOfDistSubstr(s, number) << endl;

    return 0;
}