//Contributed By : Rishabh Jain

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;


int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll maxm=arr[0];
	for(ll i=1;i<n;i++)
	{
		maxm=max(maxm,arr[i]);

	}

	ll count[maxm+1]={0};
	for(ll i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	ll j=0;
	while(j<=maxm)
	{
		while(count[j]!=0)
		{
			cout<<j<<" ";
			count[j]--;
		}
		j++;
	}	
	return 0;
}