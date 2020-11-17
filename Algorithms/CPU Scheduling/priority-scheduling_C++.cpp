#include<iostream>
using namespace std;
int main()
{
    int a[10],b[10],x[10],pr[10]={0};
    int w[10],tat[10],c[10];
    int i,j,s,cnt=0,t,n;
    double avg=0,tt=0,e;
   cout<<"\nEnter number of processes: ";
    cin>>n;
    cout<<endl;
    for(i=0;i<n;i++)
    {
      cout<<"Enter arrival time of process: ";
      cin>>a[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
      cout<<"Enter burst time of process: ";
      cin>>b[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
      cout<<"Enter priority of process: ";
      cin>>pr[i];
    }
    for(i=0;i<n;i++)
        x[i]=b[i];

    pr[9]=-1;
    for(t=0;cnt!=n;t++)
    {
        s=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=t && pr[i]>pr[s] && b[i]>0 )
                s=i;
        }
        t=t+b[s]-1;
        b[s]=-1;
        cnt++;
        e=t+1;
        c[s] = e;
        w[s] = e - a[s] - x[s];
        tat[s] = e - a[s];
    }
    cout<<"Process\t\tBurst time\tArrival time\tWaiting time\tTurnaround time\tCompletion time\tPriority";
    for(i=0;i<n;i++)
    {
        cout<<endl<<"P"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<w[i]<<"\t\t"<<tat[i]<<"\t\t"<<c[i]<<"\t\t"<<pr[i];
        avg = avg + w[i];
        tt = tt + tat[i];
    }
    cout<<"\n\nAverage waiting time: "<<avg/n;
    cout<<"\nAverage Turnaround time: "<<tt/n;
}
