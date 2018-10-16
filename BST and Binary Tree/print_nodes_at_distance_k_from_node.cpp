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
bool find(BinaryTreeNode<int> *root, int node){
    if(root == NULL) return false;

    if(root->data == node) return true;

    if(find(root->left, node)) return true;

    if(find(root->right, node)) return true;

    return false;
}

int findDistance(BinaryTreeNode<int> *root, int node, int distance){
    if(root == NULL) return -1;

    if(root->data == node) return distance;

    int leftAns = findDistance(root->left, node, distance+1);
    if(leftAns != -1) return leftAns;

    int rightAns = findDistance(root->right, node, distance+1);
    if(rightAns != -1) return rightAns;

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k, int currDistance){
    if(root == NULL) return;

    if(k == currDistance) cout << root->data << endl;

    if(find(root->left, node)) nodesAtDistanceK(root->left, node, k, currDistance-1);
    else nodesAtDistanceK(root->left, node, k, currDistance+1);

    if(find(root->right, node)) nodesAtDistanceK(root->right, node, k, currDistance-1);
    else nodesAtDistanceK(root->right, node, k, currDistance+1);
    
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int nodeDistance = findDistance(root, node, 0);

    nodesAtDistanceK(root, node, k, nodeDistance);
}
