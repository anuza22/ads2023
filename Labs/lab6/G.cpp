#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main(){
    int n; cin >> n;
    map<string, string> s;

    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> b;
        bool found = false;
        for(auto it = s.begin(); it!=s.end(); it++){
            if(it->second == a){
                s[it->first] = b;
                found = true;
                break;
            }
        }
        if(!found) s[a] = b;
    }

    cout << s.size()<< endl;

    for(auto it = s.begin(); it!=s.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    


    return 0;
}