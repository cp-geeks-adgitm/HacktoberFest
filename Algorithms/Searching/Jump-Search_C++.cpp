#include<bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int n, int element)
{
    //determining block size to be jumped
    int step = sqrt(n);

    //finding the block where element is present(iff it is present else return -1)
    int previous = 0;
    
    while(arr[min(step, n)-1] < element)
    {
        previous = step;
        step += sqrt(n);
        if(previous >= n)                       //implies element isn't available in either block
            return -1;                                
    }
   
    while(arr[previous] < element)
    {
        previous++;

        //implies element is not present in this particular block as end of block has been reached
        if(previous == min(step, n))
            return -1;
    }
    //Element found at index previous
    if(arr[previous] == element)
        return previous;
    
    return -1;
}

int main(void)
{   
    cout<<"Enter array size: "<<"\n";
    int n; cin>>n;
    int arr[n], element;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    //For sorting array(if user entered unsorted array)
    sort(arr, arr+n);
    cout<<"Enter element to be searched: "<<"\n";
    cin>>element;
    
    //storing returned index in variable called index
    int index = jumpSearch(arr, n, element);
    //printing the returned value from jumpSearch function
    cout<<"Element "<<element<<" is present at index: "<<index<<"\n";
}