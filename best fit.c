#include<stdio.h>
void main(){
	int f,a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},s[10],m,i,p[10],j,n;
	printf("Enter the no of Partitions ");
	scanf("%d",&m);
	printf("Enter the size of each partition\n");
	for(i=0;i<m;i++)
	scanf("%d",&s[i]);
	printf("Enter the no of processes ");
	scanf("%d",&n);
	printf("Enter the size of each processes\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(i=0;i<n;i++)
	{
		int min=99999;
		int ind=-1;
		for(j=0;j<m;j++)
		{
			if(s[j]>=p[i] && a[j]==-1)
			{
				if (s[j]<min)
				{
					min=s[j];
					ind=j;
				}
			}
		}
			a[ind]=i;
	}
	printf("Memory\tProcess Allocated\t Fragmented memory\n");
	printf("\n");
	for(i=0;i<m;i++)
	{
		if(a[i]!=-1)
		{
			printf("%d\t %d\t\t\t %d\n",s[i],a[i],s[i]-p[a[i]]);
			continue;
		}
		else
		printf("%d\t Not Allocated any Process %d\n",s[i],s[i]);
	}
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=0;j<n;j++)
		{
			if(i==a[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		printf("The Process %d is not allocated to any Partition\n\n",i);
	}
}



