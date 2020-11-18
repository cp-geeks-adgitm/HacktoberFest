#include<iostream>
#include "Solution.h"
using namespace std;

int partition(int arr[], int si, int ei){
   int pivot = arr[si]; 
    int count = 0;
    for (int i=si+1; i<=ei; i++){
        if(arr[i] < arr[si]){
        count ++;
        }    
           }
    int pi = count + si;
    
    
    
    int temp = arr[si];
    arr[si] = arr[pi];
    arr[pi] = temp;
    
    int i = si, j = ei;
    
    while(i<pi && j>pi){
        if(arr[i]<pivot){
            i++;
        }
        else if(arr[j]>=pivot){
            j--;
        }
        else{
            int temp = arr[i];
    		arr[i] = arr[j];
    		arr[j] = temp;
            	i++;
            	j--;
        }
    }
	return pi;
}
void sort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }
	int pivotindex = partition(arr, si, ei);
    
    sort(arr, si, pivotindex-1);
    sort(arr, pivotindex+1, ei);
                               
}
void quickSort(int arr[], int n) {
    sort(arr, 0, n-1);
  
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
