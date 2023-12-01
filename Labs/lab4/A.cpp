#include<bits/stdc++.h>
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

// bool check(Node*tree, char str){
//     if(str == 'L') {
//         if(tree->left->val) return true; 
//     }else if(str == 'R') {
//         if(tree->right->val) return true;
//     }
//     return false;
// }
bool check(Node*& tree, char str) {
    if (str == 'L') {
        if (tree && tree->left) {
            tree = tree->left; r
            return true;
        }
    } else if (str == 'R') {
        if (tree && tree->right) {
            tree = tree->right;
            return true;
        }
    }
    return false;
}
int main(){
    int n, k;
    cin >> n >> k;
    Node*root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }

    while(k--){
        string s;
        cin >> s;
        Node* currentNode = root; 

        bool isPathAvailable = true;
        for (int i = 0; i < s.size(); i++) {
            if (!check(currentNode, s[i])) {
                isPathAvailable = false;
                break;
            }
        }

        if (isPathAvailable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    


    

    return 0;
}