#include<iostream>
#include<string>
using namespace std;

string check(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]=='#'){
            s.erase(i-1, 2);
            i-=2;
        }
    }
    return s;

}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    if(check(s1) == check(s2)){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

    // cout << check(s1) << endl;
    // cout << check(s2) << endl;

    return 0;
}