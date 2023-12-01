#include<iostream>
using namespace std;

int main(){
    int n; cin >> n;
    string word = "";
    long long hash, prev = 0, two=1;

    while(n--){
        cin >> hash;
        char c = (hash - prev)/two + 97;
        word+=c;
        two*=2;
        prev = hash;
    }

    cout << word << endl;

    return 0;
}