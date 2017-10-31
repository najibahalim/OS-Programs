#include<stdio.h>
#include<assert.h>
#include<conio.h>
int available[10],max[10][10],need[10][10],allocated[10][10];
int n,m;
int work[10],finish[10]={0};
char str[20];
int find();
void main(){
	int i,j,k=0;
	clrscr();
	printf("Enter the number of Processes and Resources ");
	scanf("%d %d",&n,&m);
	assert(n<=10 && m<=10);
	printf("Enter the allocation matrix\n");
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
	printf("Enter Available Matrix ");
	for(i=0;i<m;i++){
	scanf("%d",&available[i]);
	work[i]=available[i];
	}
	//BANKERS ALGORITHM
	i=find();
	while(i!=-1)
	{
		for(j=0;j<m;j++)
			work[j]+=allocated[i][j];
		finish[i]=1;
		str[k]=i+48;
		str[k+1]='-';
		k=k+2;
		i=find();
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]!=1)
		{
			printf("NOT IN SAFE STATE");
			break;
		}
	}
	if(i==n)
	{
		printf("SAFE STATE SEQUENCE= %s",str);
	}
	getch();

}
int find(){
	int x,j;
	for(x=0;x<n;x++)
	{
		if(finish[x]==0)
		{
			for(j=0;j<m;j++)
			{
				if(work[j]>need[x][j])
					break;
			}
			if(j==m)
			{
				return x;
			}
		}
	}
	return -1;
}

