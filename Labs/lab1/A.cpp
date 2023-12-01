#include<iostream>
#include<deque>

using namespace std;

int main(){
    int n;
    cin >> n;


    for(int i = 0; i<n; i++){
        int k;
        deque<int> s;
        cin >> k;
        int p = k;

        while(s.size()<k){
            s.push_back(p);
            for(int i = 0; i<p; i++){
                s.push_back(s.front());
                s.pop_front();
            }
            p--;
        }

        while(!s.empty()){
            cout << s.back() << " ";
            s.pop_back();
        }
        cout << endl;
    }



    return 0;
}