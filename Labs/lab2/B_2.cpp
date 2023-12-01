#include<iostream>
using namespace std;

struct Node{
    string data;
    Node *next = NULL;

    // Node (string s){
    //     data = s;
    //     next = NULL;
    // }

   
};

// struct LinkedList{
//     Node*head = NULL;
   

// };

int main(){
    // LinkedList ll;
    Node * head = new Node();
    Node * start = head;
    int n, m;
    cin>>n>>m;
    while(n--){
        string a;
        cin>>a;
        head->data = a;
        head->next = new Node();
        head = head->next;
    } 
    Node * tmp = start;
    for(int i = 0; i < m - 1; i++){
        tmp = tmp->next;
    }
    head->data = start->data;
    head->next = start->next;
    start = tmp->next;
    tmp->next = new Node();
    while(start->next != NULL)
    {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}