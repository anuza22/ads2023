#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque <int> d;
    bool yep = true;
    char sim;
    int a;

    while(yep){
        cin >> sim;
        if(sim == '*'){
            if(d.empty()){
                cout << "error" << endl;
                
            }else {
                cout << d.front()+d.back() << endl;
                if(!d.empty()) d.pop_back();
                if(!d.empty()) d.pop_front();
            }
        }

        if(sim == '+'){
            cin >> a;
            d.push_front(a);
        }else if(sim == '-'){
            cin >> a;
            d.push_back(a);
        }else if(sim == '!'){
            yep = false;
        }
    }
    return 0;
}