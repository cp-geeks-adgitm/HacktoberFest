#include <iostream>
using namespace std;

int main() {
	unsigned long long t,p1,p2,k,d,f;
 cin>>t;
 while(t--)
 {
  cin>>p1>>p2>>k;
  d=p1+p2;
  f=d/k;
  if(f%2==0)
  {
    cout<<"CHEF"<<endl;;
  }
  else
  cout<<"COOK"<<endl;
 }// your code goes here
	return 0;
}
