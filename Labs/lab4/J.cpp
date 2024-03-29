#include <iostream>
#include <vector>

using namespace std;

vector <int> balanced;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node (int x) {
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct Bst {
    Node *tree;

    vector <int> nums;

    Bst () {
        this->tree = NULL;
    }

    Node *push (Node *current, int x) {
        if (current == NULL) {
            current = new Node(x);
        }
        else if (current->val > x) {
            if (current->left == NULL)
                current->left = push(current->left, x);
            else
                push(current->left, x);
        }
        else {
            if (current->right == NULL)
                current->right = push(current->right, x);
            else
                push(current->right, x);
        }
        return current;
    }

    Node *search (Node *current, int x) {
        if (current == NULL)
            return NULL;
        if (current->val == x)
            return current;
        else if (current->val > x)
            return search(current->left, x);
        else if (current->val < x)
            return search(current->right, x);
    }

    void print (Node * current){
        if(current != NULL){
            print(current->right);
            cout << current->val << " ";
            print(current->left);
        }
    }

    void inorder (Node *current){
        if(current != NULL){
            inorder(current->right);
            nums.push_back(current->val);
            inorder(current->left);
        }
        
    }

    void toBalanced(int left, int right){
        if (left > right)
            return;
        else {
            int mid = left + (right - left)/2;
            balanced.push_back(nums[mid]);
            toBalanced(left, mid - 1);
            toBalanced(mid + 1, right);
        }
    }
};

int main() {
    Bst *B = new Bst();
    int n;
    cin >> n;
    n = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (B->tree == NULL)
            B->tree = B->push(B->tree, x);
        else
            B->push(B->tree, x);
    }
    B->inorder(B->tree);
    B->toBalanced(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << balanced[i] << " ";
    }
}