#include<iostream>
#include<queue>
using namespace std;

int main(){
    deque <int> boris;
    deque <int> nursik;
    int a;

    for(int i =0; i<5; i++){
        cin >> a;
        boris.push_back(a);
    }

    for(int i =0; i<5; i++){
        cin >> a;
        nursik.push_back(a);
    }
    long long cnt = 0;

    while(!boris.empty() && !nursik.empty() && cnt<1000000){
        if(boris.front() == 9 && nursik.front() == 0){
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            cnt++;
        }else if(boris.front() == 0 && nursik.front() == 9){
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            cnt++;
        }else if(boris.front()>nursik.front()){
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            cnt++;
        }else {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            cnt++;
        }
        if(cnt>=1000000){
            cout << "blin  nichya" << endl;
            return 0;
        }

    }
    if(boris.empty()){
        cout << "Nursik " << cnt << endl;
    }else {
        cout << "Boris " << cnt << endl;
    }

    
    
    return 0;

}