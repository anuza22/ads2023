#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

Node* push(Node*tree, int val){
    if(!tree) return new Node(val);

    if(val<tree->val) tree->left = push(tree->left, val);
    if(val>tree->val) tree->right = push(tree->right, val);

    return tree;
}
void printInOrder(Node*tree){
    if(tree){
        printInOrder(tree->right);
        cout << tree->val << " ";
        printInOrder(tree->left);
    }
}
int preSum = 0;
Node*gretSumTree(Node*tree){
    if(tree){
    if(tree->right) gretSumTree(tree->right);
    preSum = tree->val = preSum + tree->val;
    if(tree->left) gretSumTree(tree->left);
    }

    return tree;
}
int main(){
    int n; cin >> n;
    Node* root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }
    Node*ans = gretSumTree(root);
    printInOrder(ans);
    return 0;
}