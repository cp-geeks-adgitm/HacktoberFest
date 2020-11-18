#include <iostream>
#include<stdlib.h>
using namespace std; 
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = new node;
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void inorder(struct node *root) {
   if (root != NULL) {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
void Search(node *root, int d) {
   int depth = 0;
   node *temp = new node;
   temp = root;
   while(temp != NULL) {
      depth++;
      if(temp->data == d) {
         cout<<"\nElement found";
         return;
      } else if(temp->data > d)
         temp = temp->left;
         else
            temp = temp->right;
   }
   cout<<"\nElement not found";
   return;
}
node* FindMin(node *Node) 
{ 
	if(Node==NULL) 
	{ 
	return NULL; 
	} 
	if(Node->left) 
	return FindMin(Node->left); 
	else 
	return Node; 
} 
node *Delete(node *Node, int data) 
{ 
		node *temp; 
		if(Node==NULL) 
		 {
		 
		cout<<"Element Not Found. Cannot Delete!!"<<endl;
	
	}
		else if(data < Node->data) 
		Node->left = Delete(Node->left, data); 
		else if(data > Node->data) 
		Node->right = Delete(Node->right, data); 
		else { 
		if(Node->right && Node->left) 
		{ 
		temp = FindMin(Node->right); 
		Node -> data = temp->data; 
		Node -> right = Delete(Node->right,temp->data); 
		} 
		else 
		{ 
		temp = Node; 
		if(Node->left == NULL) 
		Node = Node->right; 
		else if(Node->right == NULL) 
		Node = Node->left; 
		cout<<temp->data<<" element deleted\n";
		free(temp); 
		
		} 
	} 
	
	return Node; 
} 

// Driver program
int main() 
{ 
   int x,n; 
   char ch,c;
   struct node *root=NULL;
   cout<<"Enter number of nodes you want to insert\n";
   cin>>n;
   cout<<"Enter your data in binary search tree:-\n";
   cin>>x;
   root=insertNode(root,x);
   for(int i=1;i<n;i++){
   cout<<"Enter your data in binary search tree:-\n";
   cin>>x;
   insertNode(root,x);
	}
    cout << "\nInorder traversal of binary tree is \n"; 
    inorder(root);  
    int t;
    do{
  cout<<"\nWant to search(1) or delete(2) an element? (1/2)\nPress 0 for exit\n";
   cin>>t;
   if(t==1){
   	cout<<"Enter element to be searched\n";
   	cin>>x;
   	Search(root,x);}
   	else if(t==2){
	cout<<"Enter element to be deleted\n";  
	cin>>x;
   	root=Delete(root,x);
   	inorder(root);
   } else if(t==0) return 0;
}
   while(t!=0&&(t==1||t==2));
 
    return 0; 
} 
