#include <iostream>
#include "solution.h"
using namespace std;
void merge(int input[],int si,int mid,int ei)
{
    int i=si;
    int j=mid+1;
    int k=0;
    int arr[ei+1];
    while(i<mid+1&&j<ei+1)
    {
        if(input[i]>input[j])
        {
            arr[k]=input[j];
            j++;
            k++;
        }
        else
        {
            arr[k]=input[i];
            i++;
            k++;
        }
    }
    while(i<mid+1)
    {
          arr[k]=input[i];
            i++;
            k++;
    }
    while(j<ei+1)
    {
        
            arr[k]=input[j];
            j++;
            k++;
        
    }
    int z=0;
    for(int i=si;i<ei+1;i++)
    {
        input[i]=arr[z++];
    }
}
void merge_sort(int input[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;
    merge_sort(input,si,mid);
    merge_sort(input,mid+1,ei);
    merge(input,si,mid,ei);
}
void mergeSort(int input[], int size){
	// Write your code here
  
    int si=0;
    int ei= size-1;
    merge_sort(input,si,ei);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
