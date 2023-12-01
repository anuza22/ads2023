#include<iostream>
using namespace std;

int main(){
    int n, k=0, s=0;
    cin >> n

    for(int i=0; i<n; i++){
        char elite;
        cin >> elite;
        if(elite == 'K' && s<1){
            k++;
        }else if(elite == 'S' && k<1){
            s++;
        }
    }
    if(k>s){
        cout << "KATSURAGI" << endl;
    }else {
        cout << "SAKAYANAGI" << endl;
    }
    return 0;
}