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

void Answer(Node*tree){
    vector<int> sumOfValue;
    queue<Node*> bst;
    bst.push(tree);

    if(!tree) return;

    while(!bst.empty()){
        int siz = bst.size();
        int sum = 0;

        for(int i=0; i<siz; i++){
            Node* start = bst.front();
            bst.pop();

            if(start->left) bst.push(start->left);
            if(start->right) bst.push(start->right);

            sum+=start->val;
        }
        sumOfValue.push_back(sum);
    }
    cout << sumOfValue.size() << endl;

    for(int i=0; i<sumOfValue.size(); i++) cout << sumOfValue[i] << " ";

}


int main(){
    int n;
    cin >> n;
    Node * root = nullptr;

    while(n--){
        int a; cin >> a;
        root = push(root, a);
    }

    // printInOrder(root);

    Answer(root);
    return 0;
}