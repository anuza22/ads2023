#include<iostream>
#include<vector>
#include<queue>

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

// Node* find(Node* tree, int k) {
//     if (tree) {
//         if (tree->val == k) return tree;
//         if (k < tree->val) return find(tree->left, k);
//         return find(tree->right, k);
//     }
//     return NULL;
// }

Node *search (Node *root, int x) {
    if (root == NULL)
        return NULL;
    if (root->val == x)
        return root;
    Node *found = search(root->left, x);
    if (found == NULL)
    found = search(root->right, x);
    return found;
}

int getHeight(Node*tree){
    if(!tree) return 0;

    int leftHeight = getHeight(tree->left);
    int rightHeight = getHeight(tree->right);

    if(leftHeight > rightHeight) return leftHeight+1;
    return rightHeight+1;
}

int getWidth(Node*tree, int h){
    if(!tree) return 0;
    if(h == 1) return 1;
    else return getWidth(tree->left, h-1) + getWidth(tree->right, h-1);
}

int getMaxWidth(Node*tree){
    int maxSum = 0, width;
    int h = getHeight(tree);

    for(int i=1; i<=h; i++){
        width = getWidth(tree, i);
        if(width > maxSum) maxSum = width;
    }
    return maxSum;
}

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


int main() {
    int n; cin >> n;
    Node *root = NULL;
    Node *current;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z; 
        cin >> x >> y >> z;
        if (root == NULL) {
            current = new Node(x);
            root = current;
        }
        else {
            current = search(root, x);
        }
        Node *tmp = new Node(y);
        if (z == 0)
            current->left = tmp;
        else
            current->right = tmp;
    }
    cout << getMaxWidth(root);
}