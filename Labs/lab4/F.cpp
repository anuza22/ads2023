#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val){
       this->val = val;
       this->left = this->right = nullptr;
    }
};

Node* push(Node* tree, int val){
    if(!tree) return new Node(val);

    if(val < tree->val) tree->left =  push(tree->left, val);
    if(val > tree->val) tree->right = push(tree->right, val);

    return tree;
}

void printInOrder(Node*tree){
    if(tree){
        printInOrder(tree->left);
        cout << tree->val << " ";
        printInOrder(tree->right);
    }
}

int size(Node*tree){
    if(!tree) return 0;
    else return size(tree->left) + size(tree->right)+1;
}

int cnt = 0;

int check(Node*tree){
    if(!tree) return 0;

    if(tree->left && tree->right) cnt++;
    check(tree->left);
    check(tree->right);

    return cnt;
}


int main(){
    int n;
    cin >> n;
    Node * root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }

    cout << check(root) << endl;
    return 0;
}