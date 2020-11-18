//Contributed By : Rishabh Jain

#include<iostream>

using namespace std;

int maxsum(int arr[],int n)
{
	int currsum=arr[0];
	int maxsum=arr[0];
	for(int i=1;i<n;i++)
	{
		currsum=max(currsum+arr[i],arr[i]);
		if(maxsum<currsum)
			maxsum=currsum;
	}
	return maxsum;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<maxsum(arr,n)<<endl;
	}


	return 0;
}
