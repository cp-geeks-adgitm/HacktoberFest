//Author- Shadman Afzal
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void postorder(struct Node* node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

void inorder(struct Node* root) {
    struct Node* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
               cout<<curr->data<<" ";
                curr=curr->right;
            }
            else{                            
               struct Node* temp=curr->left;
             while(temp->right!=nullptr && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==nullptr){
                    temp->right=curr;
                    curr=curr->left;
                }
                else if(temp->right==curr){
                    cout<<curr->data<<" ";
                    curr=curr->right;
                    temp->right=nullptr;
               }
            }
        }
            return arr;
    }

void preorder(struct Node* node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"\nPreorder traversal of binary tree is\n";
    preorder(root);

    cout<<"\nPostorder traversal of binary tree is\n";
    postorder(root);

    cout<<"\nInorder traversal of binary tree is\n";
    inorder(root);
}
