#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    int cnt = 0;
    Node * start = head;
    if(p == 0){
        node->next = head;
        head = node;
    }else {
   } while(start != NULL){
        if(cnt == p-1){
            Node *temp = start->next;
            start->next = node;
            node->next = temp; 
        }
        cnt++;
        start = start->next;
    }
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    Node *cur = head;
    int cnt = 0;
    if(p == 0){
        head = head->next;
    }else{
        while(cur!=NULL){
        if(cnt == p-1){
           Node *tmp = cur->next->next;
           delete cur->next;
           cur->next = tmp;
        }else{
            cur = cur->next;
        }
        cnt++;
    }}
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node *cur1 = head, *cur2 = head;
    Node *prev1 = NULL, *prev2 = NULL;
    int cnt = 0;
    if (p1 == 0 and p2 == 0) {
        return head;
    }
    while(cnt < p1) {
        prev1 = cur1;
        cur1 = cur1->next;
        cnt++;
    }
    if (p1 == 0) {
        head = head->next;
        cur2 = head;
    }
    if (p1 != 0) {
        prev1->next = cur1->next;
    }
    cnt = 0;
    while(cnt < p2) {
        prev2 = cur2;
        cur2 = cur2->next;
        cnt++;
    }
    if (p2 != 0) {
        prev2->next = cur1;
        cur1->next = cur2;
    }
    else {
        cur1->next = cur2;
    }
    if (p2 == 0) {
        head = cur1;
        return head;
    }
    return head;
    
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node *cur = head, *prev = NULL, *next = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    /* write your code here */
    Node* cur = head;
    if (cur == NULL) {
        cout << -1 << "\n";
        return;
    }
    while(cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    Node *tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }

    while(x--){
        tmp->next = head;
        head = head->next;
        tmp = tmp->next;
        tmp->next = NULL;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    Node *cur = head;
    int cnt = 1;
    while(cur->next != NULL) {
        cur = cur->next;
        cnt++;
    }
    cur->next = head;
    x = cnt - x;
    while(x--) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }
        else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
