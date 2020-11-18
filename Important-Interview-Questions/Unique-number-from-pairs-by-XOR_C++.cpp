//Contributed By : Rishabh Jain

#include<iostream>

using namespace std;

void uniqueno(int arr[],int n)
{
	int xorno=0;
	for(int i=0;i<n;i++)
	{
		xorno^=arr[i];
	}

	cout<<xorno<<endl;
}

int main()
{
	int n=9;

	int arr[n]={1,9,6,7,3,9,1,6,7};

	uniqueno(arr,n);

	return 0;
}