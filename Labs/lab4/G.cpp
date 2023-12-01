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

int findDiameter(Node* tree, int& maxDiameter) {
    if (!tree) return 0;

    int leftHeight = findDiameter(tree->left, maxDiameter);
    int rightHeight = findDiameter(tree->right, maxDiameter);

    int currentDiameter = leftHeight + rightHeight;
    maxDiameter = max(maxDiameter, currentDiameter);

    return 1 + max(leftHeight, rightHeight);
}

int getMaxDis(Node* tree) {
    int maxDiameter = 0;
    findDiameter(tree, maxDiameter);
    return maxDiameter;
}

// int getRightHeight(Node*tree){
//     if(!tree) return 0;
//     int right = getRightHeight(tree->right);
//     return right+1;
// }

// int getLeftHeight(Node*tree){
//     if(!tree) return 0;
//     int left =  getLeftHeight(tree->left);
//     return left+1;
// }

// int answer(Node*tree){
//     if(!tree) return 0;

//     return getLeftHeight(tree) + getRightHeight(tree);
// }

// int getHeight(Node*tree){
//     if(!tree) return 0;

//     int leftHeight = getHeight(tree->left);
//     int rightHeight = getHeight(tree->right);

//     if(leftHeight > rightHeight) return leftHeight+1;
//     return rightHeight+1;
// }
// int max = 0;

// int getMaxDis(Node*tree){
//     if(!tree) return 0;
//     int h = getHeight(tree);

//     for(int i = 1; i<=h; i++){
//         int left = getLeftHeight(tree->left);
//         int right = getRightHeight(tree->right);
//         int ans = left + right;
//         if(ans > max) max = ans;

//     }
//     return max;
// }

void printInOrder(Node*tree){
    if(tree){
        printInOrder(tree->right);
        cout << tree->val << " ";
        printInOrder(tree->left);
    }
}

int main(){
    int n; cin >> n;
    Node * root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }
    cout << getMaxDis(root)+1 << endl;
    return 0;
}