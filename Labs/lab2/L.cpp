# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
    if(head==NULL) return 0;
    if (head->next == NULL) return head->val;

    int maxSum = head->val;
    int curSum = head-> val;

    head = head->next;

    for(int i=0; i<n-1; i++){
        curSum+=head->val;
        if(curSum<head->val)
            curSum = head->val;
        if(maxSum<curSum)
            maxSum = curSum;

        head=head->next;
    }

    return maxSum;
	// Implement this function
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
