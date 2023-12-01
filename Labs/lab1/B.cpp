#include<iostream>
#include<stack>
using namespace std;

int main(){
   int n, a;
   cin >> n;
   int arr[n];
   stack<int> st;

   for(int i=0; i<n; i++){
    cin >> a;
    arr[i] = a;
   }

   for(int i=0; i<n; i++){
    while(!st.empty() && st.top()> arr[i]) {
        st.pop();
    }
    if(st.empty()) {cout << "-1" << " ";
   }else {
    cout << st.top() << " ";
   }
   st.push(arr[i]);}


}