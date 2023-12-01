#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p = 31;
long long mod = 1e9 + 7;


int getHash(string s){
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h = h*p + (s[i] - 'a' +1);
    }
    return h;
}

int rk(string s, string t){
    int n = s.size(), m = t.size();
    int h_s = getHash(s.substr(0, m));
    int h_t = getHash(t);
    int pm = 1, cnt = 0;

    for(int i=0; i<m-1; i++) pm*=p;

    for(int i=0; i<=n-m; i++){
        if(h_s == h_t){
            cnt++;
        }

        if(i<n-m){
            h_s = (h_s - pm * (s[i]-'a'+1)) *p + (s[i+m]-'a'+1);
        }
    }
    return cnt;

}

int main() {

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int max_count = -1;

        vector<string> patterns(N);
        for (int i = 0; i < N; i++) {
            cin >> patterns[i];
        }

        string text;
        cin >> text;

        vector<string> dominatingPatterns;

        for (const string& pattern : patterns) {
            int count = rk(text, pattern);
            if (count > max_count) {
                max_count = count;
                dominatingPatterns.clear();
                dominatingPatterns.push_back(pattern);
            } else if (count == max_count) {
                dominatingPatterns.push_back(pattern);
            }
        }

        cout << max_count << endl;
        for (const string& pattern : dominatingPatterns) {
            cout << pattern << endl;
        }
    }

    return 0;
}