#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    stack<int> st;
    while(B!=A){
        st.push(B);
        if(A>B || B%2!=0)
            B++;
        else
            B/=2;
    }    
    cout << st.size() << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}