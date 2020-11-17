#include<iostream>

using namespace std;
int main()
{
      int n,temp,tt=0,min,d,i,j;
      float avg1=0,avg2=0,s=0,s1=0;

      cout<<"Enter number of processes: ";
      cin>>n;
      int a[n],b[n],e[n],t[n],w[n];
      cout<<endl;
      for(i=0;i<n;i++)
      {
            cout<<"Enter arival time of process: ";       
            cin>>a[i];
      }
      cout<<endl;
      for(i=0;i<n;i++)
      {
            cout<<"Enter brust time of process: ";      
            cin>>b[i];
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            t[i]=e[i]-a[i];
            s=s+t[i];
            w[i]=t[i]-b[i];
            s1=s1+w[i];
      }
      avg1=s/n;
      avg2=s1/n;
      cout<<endl<<"Process\t\tArrival time\tBurst time\tWaiting time\tTurnaround time";

    for(i=0;i<n;i++)
    {
    cout<<endl<<"P"<<i+1<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<w[i]<<"\t\t"<<t[i];
    }
    cout<<endl;
    cout<<"\nAverage waiting time: "<<avg2;
	cout<<"\nAverage turnaround time: "<<avg1;  
    return 0;
}
