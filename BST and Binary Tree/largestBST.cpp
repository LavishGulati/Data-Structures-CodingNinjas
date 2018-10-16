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
class solution{
public:
    int height;
    bool isBST;

    solution(int h, bool b){
        height = h;
        isBST = b;
    }
};

bool checkBST(BinaryTreeNode<int> *root){
    BinaryTreeNode<int> *rightMin = root->right;
    BinaryTreeNode<int> *leftMax  =root->left;

    if(leftMax == NULL) leftMax = root;
    if(rightMin == NULL) rightMin = root;

    while(leftMax->right != NULL) leftMax = leftMax->right;
    while(rightMin->left != NULL) rightMin = rightMin->left;

    if(root->data >= leftMax->data && root->data <= rightMin->data) return true;
    else return false;
}

solution largestBSTSubtreeHelper(BinaryTreeNode<int> *root){
    if(root == NULL) return solution(0, true);

    solution leftAns = largestBSTSubtreeHelper(root->left);
    solution rightAns = largestBSTSubtreeHelper(root->right);

    if(leftAns.isBST == false || rightAns.isBST == false){
        return solution(max(leftAns.height, rightAns.height), false);
    }

    if(checkBST(root)){
        return solution(max(leftAns.height, rightAns.height)+1, true);
    }
    else return solution(max(leftAns.height, rightAns.height), false);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    solution answer = largestBSTSubtreeHelper(root);
    return answer.height;
}
