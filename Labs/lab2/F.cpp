#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
     
};

int main(){
    ListNode *head = new ListNode();
    ListNode *start = head;
    ListNode *start1 = head;


    int n, newElement, pos;
    cin >> n;

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        head->val = a;
        head->next = new ListNode();
        head = head->next;
    }

    // cout << head->val << endl;
    // cout << start->val << endl;
    // cout << start1->val << endl;

    head = start;

    // cout << head->val << endl;
    // cout << head->next->val << endl;

    cin >> newElement;
    cin >> pos;
    ListNode *temp = new ListNode(newElement);

    for(int i = 0; i<n; i++){
        if(i == pos){
            temp->next = head;
        }

        head = head->next;
    }

    for(int i=0; i<n+1; i++){

        if(i == pos){
            start1 = temp;
            cout << start1->val <<" ";
            start1 = start1->next;
        } else {
            cout << start1->val <<" ";
            start1 = start1->next;
        }  
    }

    


    return 0;
}