#include<iostream>
using namespace std;

struct node{
    int data;
    node*nxt;

    node(int x){
        data = x;
        nxt = NULL;
    }

    node(int x, node *link){
        nxt = link;
        data = x;
    }

};

struct linked_List{
    node*head  = NULL;
    node*tail = NULL;

    void push_front(int x){
        node* new_node = new node(x);
        if (head == NULL){
            head = tail =  new_node;
        }
        else{
           tail -> nxt = new_node;
           tail = new_node;
        }
    }

    int check(int k, int n){
        node*cur = head;
        int min = 10000, pos;
        for(int i = 0; i<n; i++){
            if(min>abs(k-cur->data)){
                min = abs(k-cur->data);
                pos = i;
            }
            cur = cur->nxt;
        }
        return pos;
    }

   

};

int main(){
    int n, k;
    cin >> n;

    linked_List ll;

    for(int i =0; i<n; i++){
        int a;
        cin >> a;
        ll.push_front(a);
    }
    
    cin >> k;
  
    cout << ll.check(k, n) << endl;

    return 0;
}