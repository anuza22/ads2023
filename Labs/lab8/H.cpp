#include <iostream>
#include <map>
#include <vector>
#include <climits>  // Include the <climits> header
using namespace std;

int p = 31;

void subSTR(string s, map<string, int> &a) {
    for (size_t i = 0; i < s.size(); i++) {  // Use 'size_t' for string size
        string subsTr;
        for (size_t j = i; j < s.size(); j++) {  // Use 'size_t' for string size
            subsTr += s[j];
            a[subsTr] = 0;
        }
    }
}

int getHash(string s) {
    int h = 0;
    for (size_t i = 0; i < s.size(); i++) {  // Use 'size_t' for string size
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

void hash_code(string s, string t, map<string, int> &a) {
    size_t n = s.size(), m = t.size();  // Use 'size_t' for string size
    int h_s = getHash(s.substr(0, m));
    int h_t = getHash(t);
    int pm = 1;

    for (size_t i = 0; i < m - 1; i++) pm *= p;

    for (size_t i = 0; i <= n - m; i++) {
        if (h_s == h_t) {
            a[t]++;
        }

        if (i < n - m) {
            h_s = ((h_s - pm * (s[i] - 'a' + 1)) * p) + (s[i + m] - 'a' + 1);
        }
    }
}

int main() {
    int n, ind;
    cin >> n;
    int minLength = INT_MAX;
    vector<string> words(n);
    map<string, int> per;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() < static_cast<size_t>(minLength)) {
            minLength = s.size();
            ind = i;
        }
        words[i] = s;
    }

    subSTR(words[ind], per);

    for (int i = 0; i < n; i++) {
        for (map<string, int>::iterator it = per.begin(); it != per.end(); it++) {
            hash_code(words[i], it->first, per);
        }
    }

    int max_size = 0;
    string my_w;

    map<string, int>::iterator it1 = per.end();
    --it1;
    for (; it1 != per.begin(); --it1) {
        if (it1->second == n && it1->first.size() > max_size) {
            max_size = it1->first.size();
            my_w = it1->first;
        }
    }

    cout << my_w << endl;

    return 0;
}
