//head is the head of the linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* bubble_sort_LinkedList_itr(node* head){
    node *temp = head, *prev = NULL;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }

    for(int i = n-1; i > 0; i--){
        prev = head;
        temp = prev->next;
        for(int j = 0; j < i; j++){
            if(prev->data > temp->data){
                int x = prev->data;
                prev->data = temp->data;
                temp->data = x;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}
