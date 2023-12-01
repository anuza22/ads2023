#include<iostream>
using namespace std;

struct Node{
    string data;
    Node *next;

    Node (string s){
        data = s;
        next = NULL;
    }

    Node (string s, Node*link){
        data = s;
        next = link;
    }
};

struct LinkedList{
    Node*head = NULL;
    Node*tail = NULL;

    void push_front(string s){
        Node* new_node = new Node(s);
        if (head == NULL){
            head = tail =  new_node;
        }
        else{
           tail -> next = new_node;
           tail = new_node;
        }
    }

    
    string front(){
        Node*cur = head;
        return cur->data;
    }

};

int main(){
    LinkedList ll;

    ll.push_front("ana");
    ll.push_front("dna");
    ll.push_front("cna");
    cout << ll.front() << endl;
    return 0;
}