#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    long long val;
    Node *left;
    Node *right;

    Node(long long val){
       this->val = val;
       this->left = this->right = nullptr;
    }
};

Node* push(Node* tree, long long val){
    if(!tree) return new Node(val);

    if(val < tree->val) tree->left =  push(tree->left, val);
    if(val > tree->val) tree->right = push(tree->right, val);

    return tree;
}

void printInOrder(Node*tree){
    if(tree){
        cout << tree->val << " ";
        printInOrder(tree->left);
        printInOrder(tree->right);
    }
}

Node*find(Node*tree, long long k){
    if(tree){
    if(tree->val == k) return tree;
    if (k < tree->val) return find(tree->left, k);
    return find(tree->right, k);
    }
}


int main(){
    long long n;
    cin >> n;
    Node * root = nullptr;

    while(n--){
        long long a; cin >> a;
        root = push(root, a);
    }

    long long k; cin >> k;

    Node*ans = find(root, k);
    printInOrder(ans);

    
    return 0;
}