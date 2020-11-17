#include <iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)

	{std::vector<int> a;
	    int c=0;
	    int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{int ar;
	 cin>>ar;
	    arr.push_back(ar);
	}
	for(int i=0;i<n;i++)
	{
	    if(arr[i]==1)
	    a.push_back(i);
	}

	    for(int i=0;i<a.size();i++)
	    {
	        for(int j=i+1;j<a.size();j++)
	        {
	            if((a[j]-a[i])<6)
	            c++;

	        }
	    }
	    if(c!=0)
	    cout<<"NO"<<endl;
	    else
	    cout<<"YES"<<endl;

	    a.clear();
	    arr.clear();








	}
	return 0;
}
