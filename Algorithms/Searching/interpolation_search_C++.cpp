#include<iostream>
#include<vector>
using namespace std; 

// Interpolation Search Algo Start
int interpolationSearch(vector<int> arr, int n, int x) 
{ 
    // Declarations of low and high point
    int lo = 0, hi = (n - 1); 

    // In sorted array element must be between lo and hi
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
    { 
        if (lo == hi) 
        { 
            if (arr[lo] == x) return lo; 
            return -1; 
        } 
        
        // Probing position, pos
        int pos = lo + (((double)(hi - lo) / 
            (arr[hi] - arr[lo])) * (x - arr[lo])); 

        // Target found 
        if (arr[pos] == x) 
            return pos; 
        
        // Element a pos is larger than x, so it must be in upper part
        if (arr[pos] < x) 
            lo = pos + 1; 

        // Element a pos is smaller than x, so it must be in lower part
        else
            hi = pos - 1; 
    } 
    return -1; 
}  
int main() 
{ 
    int n,x,i,temp;
    vector<int> arr;
    cout<<"Enter the number of elements of array\n";
    cin>>n;

    cout<<"Enter sorted array\n";
    for(i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<"Enter element to be searched\n";
    cin>>x; 
    int index = interpolationSearch(arr, n, x); 

    if (index != -1) 
        cout << "Element found at index " << index+1; 
    else
        cout << "Element not found."; 
    return 0; 
} 
