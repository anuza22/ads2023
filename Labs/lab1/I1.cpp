#include <iostream>
#include <string>

using namespace std;

int count1(string s, char c){
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==c) cnt++;
    }
    return cnt;

}

int main() {
    int n, f=1, s=1;
    cin >> n;
    string votes;
    cin >> votes;
    char now = votes[0];

    for(int i=1; i<n; i++){
        if(count1(votes, 'K')==0 || count1(votes, 'S')){
            break;
        }
        if(now == votes[i]){
            f++;
        }else if (now != votes[i] && f>0 && now != 'X' ){
            votes[i] = 'X';
            f--;
        } else if(i==n-1){
            if(f==0){
                now = votes[i];
            }
            i=0;
        }
    }

    if(votes[0]=='S'){
        cout << "SAKAYANAGI" << endl;
    }else{
        cout << "KATSURAGI" << endl;
    }

    
    return 0;
}
