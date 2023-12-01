#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


int kmp(string a){
    int size = a.size();

    vector<int> prefixfunc(a.size());
    int pointer = 0;
    int i = 1;

    
    while(i < a.size()){
        if(a[pointer] == a[i]){
            pointer++;
            prefixfunc[i] = pointer;
            i++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunc[pointer - 1];
        }
    }
    return prefixfunc[a.size() - 1];
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--){
        string a;
        int x;
        cin >> a >> x;
        int cnt = kmp(a);
        cout << x * a.size() - (x - 1) * cnt << ENDL;DF
    }

    asasasasasas.size() - 2*2 = 8u
    


    endd
}
