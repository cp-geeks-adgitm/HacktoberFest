#include<iostream>
using namespace std;

struct node
{
	string data;
	node *next;
};   
class Stack
{
	node *front;  // points to head in the list
	public:
	Stack()
	{
	front=NULL;                                                          
	}
	// method using push to add a data element
	void push(string);
	// pop method to remove data element
	void pop();
	// top method to return top data element from stack
	string top();
	void printS();
};
                        
void Stack :: push(string a)
{
	// To create a new node
	node *temp;
	temp = new node();
	// Add data to node
	temp->data = a;
	temp->next=NULL;
	// adding data to front node      
	if(front == NULL)
	{
		front=temp;
	}
	else
	{
		temp->next = front;
		front=temp;
	}
}
void Stack::pop()
{
	if(front==NULL){
		cout<<"STACK IS EMPTY";
	}
	else{
		cout<<front->data<<" element popped from stack";
		front=front->next;	
		}
}
string Stack::top(){
return front->data;
}
void Stack::printS(){
	node *pt;
	pt=front;
	while(pt!=NULL)
{
cout<<pt->data<<" ";
pt=pt->next;
}
cout<<endl;
}

int main()
{
int ch;
string x;
Stack A;
cout << "STACK OPERATIONS\n\n";
  do
    {      
cout << "\n\n1. PUSH 2. POP 3.TOP 4.DISPLAY 5.QUIT\n\nEnter the choice :: ";
 cin >> ch;
 switch (ch)
	{case 1: cout<<"Enter state to be inserted:: "; cin>>x; A.push(x); break;
	case 2: A.pop(); break;
	case 3: cout<<"Top of the stack is "<<A.top(); break;
	case 4: A.printS(); break;
	default:cout<<"Invalid"; exit(0);
    }
}while(ch<5);
return 0;
}
