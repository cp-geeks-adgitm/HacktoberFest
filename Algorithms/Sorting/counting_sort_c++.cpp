#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{   
   // Declarations
   int n,i,j,min=INT_MIN,max=INT_MAX,range,temp;
   vector<int> arr,output,count;
   
   // Array length
   cout<<"Enter array length\n";
   cin>>n;

   // Array Input
   for(i=0;i<n;i++){
       cin>>temp;
       arr.push_back(temp);
       if(arr[i]<min){
           min=arr[i];
       }
       if(arr[i]>max){
           max=arr[i];
       }
   }
   
   range = max - min + 1;
   
   // Counting Sort Algo Start
   for(i=0;i<range;i++)
   count[i]=0;
   
   // Frequency of occurance of each element
   for(j=0;j<n;j++)
   count[arr[j]-min]++;
   
   // Making count cumulative sum array/list
   for(i=1;i<count.size();i++){
       count[i]+=count[i-1];
   }
   
   for(i=n-1;i>=0;i--){
       output[count[arr[i]-min]-1]=arr[i];
       count[arr[i]-min]--;
   }
   
   for(i=0;i<n;i++){
       cout<<output[i]<<" ";
   }
   
   return 0;
}
