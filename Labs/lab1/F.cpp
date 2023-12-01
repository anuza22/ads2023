#include<iostream>
using namespace std;

bool isPrime(int a){
    if(a==1) return false;

    for(int i=2; i<=a/i; i++){
        if(a%i==0) return false;
    }
    return true;
}

int main(){
    int a = 1, cnt=0, num;
    cin >> num;
    while(cnt!=num){
        a++;
        if(isPrime(a)) cnt++;
    }

    cout << a << endl;


    
    return 0;

}