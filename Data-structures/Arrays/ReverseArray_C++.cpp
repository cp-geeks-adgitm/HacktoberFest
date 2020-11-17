#include <iostream.h>
#include <conio.h>

using namespace std;
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"the array is :" <<a[i]<<" ";;
    }
    cout<<endl;
}
void reversearray(int a[],int n)
{
    int temp;
    int i=0;
    int j=n-1;
    while(i<j)
    {
        temp=a[i];
        a[i++]=a[j];
        a[j--]=temp;
    }
}
int main()
{
    int n;
    //problem- we need to define what is n else program will wait for input and user won't know
    cin>>n;
    int a[100000];
    //problem- this funtion will take input till 1000 and not stop until then
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    reversearray(a,n);
    printarray(a,n);
}
getch();
