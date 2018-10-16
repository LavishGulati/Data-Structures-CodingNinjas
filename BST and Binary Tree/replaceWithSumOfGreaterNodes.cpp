// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x)->begin(), (x)->end()
#define pbi pair<BinaryTreeNode<int> *, int>

void fillOutput(BinaryTreeNode<int> *root, vector<int> *output){
    if(root == NULL) return;

    output->push_back(root->data);
    fillOutput(root->left, output);
    fillOutput(root->right, output);
}

void updateTree(BinaryTreeNode<int> *root, map<int, int> m){
    if(root == NULL) return;

    int x = m[root->data];
    root->data = x;
    updateTree(root->left, m);
    updateTree(root->right, m);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    vector<int> *output = new vector<int>;
    fillOutput(root, output);

    sort(all(output));

    map<int, int> m;
    int i = (output->size())-1;
    m[output->at(i)] = output->at(i);
    i--;
    for(; i >= 0; i--){
        m[output->at(i)] = output->at(i) + output->at(i+1);
        output->at(i) += output->at(i+1);
    }

    updateTree(root, m);
}
