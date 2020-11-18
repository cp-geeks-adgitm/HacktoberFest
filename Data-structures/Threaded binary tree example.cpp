*/Implement a menu driven program for threaded binary tree for given data and provide facility for
Insertion, Display ( Inorder (Non-recursive), Preorder(Recursive),Postorder(Recursive) and search
particular data of given data element.*/
/============================================================================ /

#include <iostream>
#include <cstring>
using namespace std;
class node
{public:
 int data;
 node *left, *right;
 int ltag, rtag;
public:
 void getdata()
 {
 cout<<"Enter the data"<<endl;
 cin>>data;
 }
};
class TBT
{public:
 node *root, *head;
 TBT()
 { root=NULL; }
 void create();
 void insert(node *root, node *temp);
 void inorder_display(node *root);
 void preorder_display(node *root);
 void postorder_display(node *root);
 void search(node *root, int c);
};
/*ltag=1 for left child
*rtag=1 for right child
*/
void TBT::create()
{
 node *temp;
 int ch;
 do
 {
 temp=new node;
 temp->getdata();
 temp->right=NULL;
 temp->left=NULL;
 temp->ltag=0;
 temp->rtag=0;
 if(root==NULL)
 {
 root=temp;
 head=new node;
 head->left=root;
 head->right=NULL;
 head->data=-999;
 head->ltag=1;
 head->rtag=0;
 root->left=head;
 root->right=head;
 }
 else
 {
 insert(root,temp);
 }
 cout<<"Do you want to continue to add data(1/0)"<<endl;
 cin>>ch;
 }while(ch==1);
}
void TBT::insert(node *root, node *temp)
{
 if(temp->data<root->data)
 {
 if(root->ltag==0)
 {
 temp->left=root->left;
 temp->right=root;
root->left=temp;
 root->ltag=1;
 }
 else
 insert(root->left,temp);
 }
 else
 {
 if(root->rtag==0)
 {
 temp->right=root->right;
 temp->left=root;
root->right=temp;
root->rtag=1;
 }
 else
 insert(root->right,temp);
 }
}
void TBT::inorder_display(node *root)
{
 node *p;
 root=head->left;
 p=root->left;
 while(p!=head)
 {
 while(p->ltag==1)
 p=p->left;
 cout<<p->data;
 while(p->rtag==1)
 {
 p=p->right;
 if(p==head)
 break;
 cout<<p->data;
 }
 p=p->right;
 if(p==head)
 break;
 }
}
void TBT::preorder_display(node *root)
{
 cout<<"Data :"<<root->data<<endl;
 if(root->ltag==1)
 preorder_display(root->left);
 if(root->rtag==1)
 preorder_display(root->right);
}
void TBT::postorder_display(node *root)
{
 if(root->ltag==1)
 postorder_display(root->left);
 if(root->rtag==1)
 postorder_display(root->right);
 cout<<"Data :"<<root->data<<endl;
}
int main()
{
 int choice, ch;
 TBT m;
 node *n;
 n=new node;
 n->right=NULL;
 n->left=NULL;
 n->ltag=0;
 n->rtag=0;
 do
 {
 cout<<"1. Create "<<endl;
 cout<<"2. Insert "<<endl;
 cout<<"3. In-order Display "<<endl;
 cout<<"4. Pre-order Display "<<endl;
 cout<<"5. Post-order Display "<<endl;
 cout<<"Enter your choice :"<<endl;
 cin>>choice;
 switch(choice)
 {
 case 1:
 m.create();
break;
 case 2:
 n->getdata();
m.insert(n,m.root);
break;
 case 3:
 m.inorder_display(m.root);
break;
 case 4:
 m.preorder_display(m.root);
break;
 case 5:
 m.postorder_display(m.root);
break;
 default:
 cout<<"Invalid choice"<<endl;
 }
 cout<<"Do you want to continue(1/0)"<<endl;
 cin>>ch;
 }while(ch==1);
 return 0;
}
/*
1. Create
2. Insert
3. In-order Display
4. Pre-order Display
5. Post-order Display
Enter your choice :
1
Enter the data
1
Do you want to continue to add data(1/0)
1
Enter the data
2
Do you want to continue to add data(1/0)
1
Enter the data
2
Do you want to continue to add data(1/0)
1
Enter the data
4
Do you want to continue to add data(1/0)
0
Do you want to continue(1/0)
1
1. Create
2. Insert
3. In-order Display
4. Pre-order Display
5. Post-order Display
Enter your choice :
4
Data :1
Data :2
Data :2
Data :4
Do you want to continue(1/0)
1
1. Create
2. Insert
3. In-order Display
4. Pre-order Display
5. Post-order Display
Enter your choice :
2
Enter the data
6
Do you want to continue(1/0)
0
*/
