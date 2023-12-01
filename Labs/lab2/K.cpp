#include<iostream>
using namespace std;

struct ListNode {
    string val;
    ListNode *next;
    ListNode() : val(NULL), next(nullptr) {}
    ListNode(string x) : val(x), next(nullptr) {}
    ListNode(string x, ListNode *next) : val(x), next(next) {}
     
};

int main(){
    int n, k;
    string a, leftmost;

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> k;
        ListNode *head = new ListNode();
        ListNode *start = head;
        for(int j=0; j<k; j++){
            cin >> a;
            if(a == leftmost) {
                head->val = a;}
            else {
                head->val = "-1";
            }
            if(j==0) leftmost = a;
            head = head->next;
        }
        while(start->next != NULL)
    {
        cout << start->val << endl;
        start = start->next;
    }
    }
    return 0;

}