#include<iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    Node * next = NULL;

};

int main(){

    int n;
    cin >> n;
    Node * head = new Node();
    Node * start = head;
    int maxRep=0;
    map<int, int> m;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        m[a]++;
        if(m[a]>maxRep) maxRep=m[a];
    }

    for(auto it = m.rbegin(); it != m.rend(); ++it){
        if(it->second == maxRep){
            cout << it->first << " ";
        }
    }
    return 0;
}