#include<iostream>
using namespace std;

template<class T>

void selection(T a[], int n)
{
	int i,j,temp,small;
	
	for(i=0;i<n-1;i++)
	
	{
		small=i;
		
		for(j=i+1;j<n;j++)
		
  		if(a[j]<a[small])
		
  		small=j;
		
  		if(small!=i)
		
		{
		
			temp=a[i];
			
			a[i]=a[small];
			
			a[small]=temp;
			
		}
		
	}
		cout<<"\nThe sorted array is: ";

	for(int i=0;i<n;i++)

		cout<<a[i]<<" ";
}



template<class T>

void bubble(T a[],int n)
{
	int i,j,temp;

	for(i=0;i<n-1;i++)

	{
		for(j=0;j<(n-1-i);j++)

			if(a[j]>a[j+1])

			{

				temp=a[j]; 	  

				a[j]=a[j+1];

				a[j+1]=temp;

			}

	}
	cout<<"\nThe sorted array is: ";

	for(int i=0;i<n;i++)

		cout<<a[i]<<" ";
}
        


template<class T>

void insertion(T a[], int n)

{

	int i,j,temp;

	for(i=1;i<n;i++)

	{

		temp=a[i];

		j=i-1;

		while((temp<a[j]) && (j>=0))

		{

			a[j+1]=a[j];

			j--;

		}

		a[j+1]=temp;

	}
         cout<<"\nThe sorted array is: ";

	    for(int i=0;i<n;i++)

		cout<<a[i]<<" ";
}



int main()
{	
int a[10],n,i,choice;
cout<<"enter the number of array elements: ";
cin>>n;
cout<<"\nenter the array: ";
for(i=0;i<n;i++)
{
cin>>a[i];
}
do

	{

		cout<<"\n\nMENU";

		cout<<"\n1. Sort the array using selection sort method";

		cout<<"\n2. Sort the array using bubble sort method";

		cout<<"\n3. Sort the array using insertion sort method";

		cout<<"\n4. Exit";

		cout<<"\n\nEnter your choice 1-4: ";

		cin>>choice;

		switch(choice)

		{

			case 1:	selection(a,n);
			        

				break;

			case 2:	bubble(a,n);

				break;

			case 3:	insertion(a,n);

				break;

			case 4:	break;

			default:cout<<"\nInvalid choice";

		}

	}while(choice!=4);
	
	return 1;

}

