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
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int> *helper){
    if(k < 0) return;

    if(root->left == NULL && root->right == NULL){
        helper->push_back(root->data);
        if(k-(root->data) == 0){
            for(int i = 0; i < helper->size(); i++){
                cout << helper->at(i) << " ";
            }
            cout << endl;
        }
        helper->pop_back();
    }
    else if(root->left == NULL){
        helper->push_back(root->data);
        rootToLeafPathsSumToK(root->right, k-(root->data), helper);
        helper->pop_back();
    }
    else if(root->right == NULL){
        helper->push_back(root->data);
        rootToLeafPathsSumToK(root->left, k-(root->data), helper);
        helper->pop_back();
    }
    else{
        helper->push_back(root->data);
        rootToLeafPathsSumToK(root->right, k-(root->data), helper);
        helper->pop_back();

        helper->push_back(root->data);
        rootToLeafPathsSumToK(root->left, k-(root->data), helper);
        helper->pop_back();
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> *helper = new vector<int>;
    rootToLeafPathsSumToK(root, k, helper);
}
