#include<iostream>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    int mult;
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
        this->mult = 1;
    }
};

Node*insert(Node*tree, int val){
    if(!tree) return new Node(val);
    if(tree->val == val) tree->mult+=1;

    if(val < tree->val) tree->left = insert(tree->left, val);
    if(val > tree->val) tree->right = insert(tree->right, val);

    return tree;
}

Node*getMin(Node*tree){
    if(tree->left == nullptr) return tree;
    getMin(tree->left);
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

Node*remove(Node*tree, int val){
    if(!tree) return nullptr;
    else if (val < tree->val) tree->left = remove(tree->left, val);
    else if (val > tree->val) tree->right = remove(tree->right, val);
    else if(tree->mult == 0){
        if(tree->left == nullptr && tree->right == nullptr){
            delete tree;
            return nullptr;
        }else if(tree->right == nullptr){
            Node*temp = tree->left;
            delete tree;
            return temp;
        }else if(tree->left == nullptr){
            Node*temp = tree->right;
            delete tree;
            return temp;
        }else {
            Node*temp = getMin(tree->right);
            tree->val = temp->val;
            tree->right = remove(tree->right, temp->val);
            return tree;
        }
    }else {
        tree->mult-=1;
    }

    return tree;

}


int main(){
    int n; cin >> n;
    Node *tree = NULL;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int x; cin >> x;
        if (s == "insert") {
            tree = insert(tree, x);
        }
        if (s == "cnt") {
            Node *found = find(tree, x);
            if(found == NULL)
                cout << 0 << "\n";
            else
                cout << found->mult << "\n";
        }
        if (s == "delete") {
            remove(tree, x);
        }
    }
}