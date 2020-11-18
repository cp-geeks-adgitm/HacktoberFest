#include <iostream>
using namespace std;

void InsertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int element=a[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(element<a[j])
            {
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=element;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    InsertionSort(a,n);
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
}
