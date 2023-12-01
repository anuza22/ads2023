#include <iostream>
#include <string>

using namespace std;

string er(string s){
    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]){
            s.erase(i,1);
            i--;
        }
    }
    return s;

}

int main() {
    int n, f=1;
    cin >> n;
    string votes;
    cin >> votes;
    char now = votes[0];

    for(int i=0; i<n; i++){
        int ch = i+1;
        if(er(votes).size() == 1){
            break;
        if(f==0){
            now = votes[i];
        }else if(ch>=n){
            i=0;
        }else if(now==votes[ch]){
            f++;
        }else if(now!=votes[ch]){
            votes.erase(ch, 1);
            f--;
        }
    }
    // KXKS

    // if(count1(votes, 'K') < count1(votes, 'S')){
    //     cout << "SAKAYANAGI" << endl;
    // }else{
    //     cout << "KATSURAGI" << endl;
    // }
    cout << votes[0] << endl;

    
    return 0;
}
}