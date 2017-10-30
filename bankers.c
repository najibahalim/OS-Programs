#include<stdio.h>
int available[10];
int allocated[10][10];
int max[10][10];
int need[10][10];
int pf;
void main(){
	int n,m,index=0,count=0;
	int i,j,request[10],work[10],ans[10];
	int flag[10]={0};
	pf=0;
	printf("Enter the number of Processes and reosurces ");
	scanf("%d %d",&n,&m);
	printf("Enter the available matrix ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&available[i]);
	}
	printf("Enter the allocated matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	printf("Enter the max matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-allocated[i][j];
		}
	}
	printf("\n");
	
	//Safety Algorithm
	index=0;
	for(i=0;i<m;i++)
	{
		work[i]=available[i];
	}
	for(i=0;;i=(i+1)%n)
	{
		int x=0;
		for(j=0;j<m;j++)
		if(need[i][j]>work[j])
		{
			x=1;
			break;
		}
		if(flag[i]!=0)
		x=1;
		if(x==0)
		{
			for(j=0;j<m;j++)
				work[j]+=need[i][j];
			flag[i]=1;
			ans[index++]=i;
			count=0;
		}
		else count++;
		x=0;
		for(j=0;j<n;j++)
		{
			if(flag[j]!=1){
				x=1;
				break;
			}
		}
		if(x==0)
		break;
		else if(count>=n)
		break;
	}
	if(count==0)
	{
		printf("\nSafety Sequence ");
		for(i=0;i<n;i++)
		printf("P%d ",ans[i]);
	}
	else
	{
		printf("Not in safe state");
	}
}
