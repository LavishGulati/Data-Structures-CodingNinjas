//head is the head of the linked list, n is number of elements to be reversed
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
#include <bits/stdc++.h>
using namespace std;

void fillOutput(vector<int> *output, node *temp, int id, int n){
    if(temp == NULL || id == n) return;

    fillOutput(output, temp->next, id+1, n);
    output->push_back(temp->data);
}

node* kReverse(node*head,int n){
    vector<int> *output = new vector<int>;
    node *temp = head;
    while(temp != NULL){
        fillOutput(output, temp, 0, n);
        for(int i = 0; i < n; i++){
            if(temp == NULL) break;
            temp = temp->next;
        }
    }

    node *newHead = new node(output->at(0));
    node *rear = newHead;
    for(int i = 1; i < output->size(); i++){
        rear->next = new node(output->at(i));
        rear = rear->next;
    }

    return newHead;
}
