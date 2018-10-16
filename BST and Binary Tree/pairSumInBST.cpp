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
bool find(BinaryTreeNode<int> *root, int element){
    BinaryTreeNode<int> *temp = root;
    while(temp != NULL){
        if(temp->data == element) return true;

        if(element < temp->data) temp = temp->left;
        else temp = temp->right;
    }

    return false;
}

void printNodesSumToS(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, int s){
    if(node == NULL) return;

    int x, y;
    x = node->data;
    if(double(x) < double(s)/2){
        y = s-x;
        if(find(root, y)){
            if(y < x) cout << y << " " << x << endl;
            else cout << x << " " << y << endl;
        }
    }

    printNodesSumToS(root, node->left, s);
    printNodesSumToS(root, node->right, s);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    printNodesSumToS(root, root, s);
}
