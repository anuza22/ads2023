#include<iostream>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;

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

Node* find(Node* tree, int k) {
    if (tree) {
        if (tree->val == k) return tree;
        if (k < tree->val) return find(tree->left, k);
        return find(tree->right, k);
    }
    return nullptr;
}

int cnt = 0;

int solution(Node*tree){
    if(tree){
        cnt++;
        solution(tree->left);
        solution(tree->right);
    }
    return cnt;
}

int size(Node*tree){
    if(!tree) return 0;
    else return size(tree->left) + size(tree->right)+1;
}

int main(){
    int n; cin >> n;
    Node*root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }
    int k; cin >> k;
    Node*res = find(root, k);
    cout << solution(res) << endl;
    return 0;
}