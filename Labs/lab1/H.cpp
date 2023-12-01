#include<iostream>
using namespace std;

int main(){

    int a;
    cin >> a;

    bool yes = true;

    if(a==1) yes = false;

    for(int i=2; i<=a/i; i++){
        if(a%i==0){
            yes = false;
        }
    }

    if(yes){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    

    
    return 0;

}