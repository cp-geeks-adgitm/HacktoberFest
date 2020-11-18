//Author - Shadman Afzal
//Quicksort

#include <iostream>
#include <vector>
using namespace std;

int Partitioning(vector<int> &arr,int p,int r) // Partitioning of the arr
{
    int i = p - 1,pivot = r;
    for(int j=p;j<=r;j++)
    {
        if(arr[j]<=arr[pivot])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}

void quicksort(vector <int> &arr,int p,int r)
{
    if(p<r)
    {
        int q = Partitioning(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
     }
}

int main()
{
    vector<int > arr;
    int n;
    cout<<"Enter the size of the Array"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    while(n--)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"\nUNSORTED ARRAY"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,arr.size()-1);
    cout<<"\nSORTED ARRAY"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
