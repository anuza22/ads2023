#include <iostream>
#include <vector>
using namespace std;
vector<int > v;

void f(int k){
    int i = 0;
    int s = 0;
    for(int j=0; j<v.size(); j++){
        if (v[j]<=k){
            i+=v[j];
            s++;
        }
    }
    cout << s <<" "<< i << endl;

}



int main(){
    int n, a;
    cin >> n;
    int k;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    int b;
    cin >> a;
    for(int i=0; i<a; i++){
        cin >> b;
        f(b);
    }
    return 0;
    



}