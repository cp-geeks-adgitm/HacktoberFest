#include<stdio.h>
#include<time.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
int main()
{
	 time_t start, end;
  	double tc;

	int a[50],n,i;
	printf("Enter no of elements you want to sort:");
	scanf("%d",&n);
	printf("Enter elements:");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergesort(a,0,n-1);

	printf("\nSorted array :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	 tc=(difftime(end,start)/CLOCKS_PER_SEC);
     printf("\n Time efficiency : %lf",tc);
		return 0;
}

void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		merge(a,i,mid,mid+1,j);
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int arr[50];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
			arr[k++]=a[i++];
		else
			arr[k++]=a[j++];
	}
	while(i<=j1)
		arr[k++]=a[i++];

	while(j<=j2)
		arr[k++]=a[j++];

	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=arr[j];
}
