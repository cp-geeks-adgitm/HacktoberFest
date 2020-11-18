/*Design and implement a program to generate a computerized telephone directory for a cellular
service consisting of name and cell phone number. Present the user with a menu that allows the
user to search the directory for a specified record, insert a new record, delete an existing record, or
print the entire phone list*/
include <iostream>
#include <cstring>
using namespace std;
class node
{public:
 double phone;
 char name[50];
 node *left, *right;
public:
 void getdata()
 {
 cout<<"Enter the name of person"<<endl;
 cin>>name;
 cout<<"Enter the phone number"<<endl;
 cin>>phone;
 }
};
class bst
{public:
 node *root;
 bst()
 { root=NULL; }
 void create();
 void insert_new(node *root, node *temp);
 void inorder_display(node *root);
 void preorder_display(node *root);
 void postorder_display(node *root);
 void search_list(node *root, char contact[50]);
};
void bst::create()
{
 node *temp;
 int ch;
 do
 {
 temp=new node;
 temp->getdata();
 temp->right=NULL;
 temp->left=NULL;
 if(root==NULL)
 root=temp;
 else
 {
 insert_new(root,temp);
 }
 cout<<"Do you want to continue to add numbers(1/0)"<<endl;
 cin>>ch;
 }while(ch==1);
}
void bst::insert_new(node *root, node *temp)
{
 int r;
 r=strcmp(root->name,temp->name);
 if(r<0)
 {
 if(root->right==NULL)
 root->right=temp;
 else
 insert_new(root->right,temp);
 }
 else if(r==0)
 cout<<"Cannot add"<<endl;
 else
 {
 if(root->left==NULL)
 root->left=temp;
 else
 insert_new(root->left,temp);
 }
}
void bst::inorder_display(node *root)
{
 if(root !=NULL)
 {
 inorder_display(root->left);
 cout<<"Name :"<<root->name<<endl;
 cout<<"Phone number :"<<root->phone<<endl;
 inorder_display(root->right);
 }
}
void bst::preorder_display(node *root)
{
 if(root !=NULL)
 {
 cout<<"Name :"<<root->name<<endl;
 cout<<"Phone number :"<<root->phone<<endl;
 preorder_display(root->left);
 preorder_display(root->right);
 }
}
void bst::postorder_display(node *root)
{
 if(root !=NULL)
 {
 postorder_display(root->left);
 postorder_display(root->right);
 cout<<"Name :"<<root->name<<endl;
 cout<<"Phone number :"<<root->phone<<endl;
 }
}
void bst::search_list(node *root, char contact[50])
{
 int f=0;
 node *curr;
 curr = root;
 int r;
 r=strcmp(curr->name,contact);
 while(curr!=NULL)
 {
 if(r < 0)
 search_list(curr->left, contact);
 if(r > 0)
 search_list(curr->right, contact);
 if(r==0)
 {
 f=1;
break;
 }
 }
 if(f==0)
 cout<<contact<<" does not exist";
 else
 {
 cout<<contact<<" found";
 cout<<curr;
 }
}
int main()
{
 int choice, ch;
 bst m;
 char cont[50];
 node *n;
 n=new node;
 n->right=NULL;
 n->left=NULL;
 do
 {
 cout<<"1. Create "<<endl;
 cout<<"2. Insert "<<endl;
 cout<<"3. In-order Display "<<endl;
 cout<<"4. Pre-order Display "<<endl;
 cout<<"5. Post-order Display "<<endl;
 cout<<"6. Search"<<endl;
 cout<<"Enter your choice :"<<endl;
 cin>>choice;
 switch(choice)
 {
 case 1:
 m.create();
break;
 case 2:
 n->getdata();
 m.insert_new(n,m.root);
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
 case 6:
 cout<<"Enter name to search";
cin>>cont;
m.search_list(m.root,cont);
break;
 default:
 cout<<"Invalid choice"<<endl;
 }
 cout<<"Do you want to continue(1/0)"<<endl;
cin>>ch;
 }while(ch==1);
 return 0;
}
