#include<iostream>
#include<vector>

using namespace std;

void prefix(string s, vector<int>&p){
    int n = s.size();
    p[0] = 0;

    for(int i=1; i<n; i++){
        int j=p[i-1];

        while(j>0 && s[i] != s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j]){
            p[i] = j+1;
        } else{
            p[i] = j;
        } 
    }
}

int KMP(string s){
    int s_siz = s.size(), cnt=0;
    vector<int> p(s_siz, 0);
    prefix(s, p);
    for(int i=1; i<p.size(); i++){
        if(i%2==0){
            int k = i - p[i-1];
            if((i/k)%2==0) cnt++;
        }
    }
    return cnt;
}


int main(){
    string s; cin >> s;
    cout << KMP(s) << endl;
    return 0;
}