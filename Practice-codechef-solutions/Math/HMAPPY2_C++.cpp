#include <iostream>
using namespace std;


unsigned long long hcf(unsigned long long a, unsigned long long b)
{
    if(a%b==0)
        return b;
    else
        hcf(b,a%b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return (a*b)/hcf(a,b);

}
int main()
{
	unsigned long long t;
	cin>>t;
	while(t--)
      {
        //cout<<lcm(4,2);
        unsigned long long n,a,b,k,f;
        cin>>n>>a>>b>>k;
        //cout<<n<<a<<b<<k;
        f=(n/a)+(n/b)-((n/lcm(a,b))*2);
        if(f>=k)
        cout<<"Win"<<endl;
        else
        cout<<"Lose"<<endl;
    }
	return 0;
}
