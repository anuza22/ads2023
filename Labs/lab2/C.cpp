#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;

};

int main(){
    int n;
    cin >> n;
    Node * head = new Node();
    Node * start = head;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(i%2==0){
            head->data = a;
            head->next = new Node();
            head = head->next;
        }
    }
    // head->data = start->data;
    // head->next = start->next;
   
    while(start->next != NULL)
    {
        cout << start->data << " ";
        start = start->next;
    }
    return 0;
}