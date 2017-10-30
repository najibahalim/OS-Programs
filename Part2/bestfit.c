#include<stdio.h>
int res[10],ip[10],n,m,all[10],flag[10]={0};
void main()
{
	ip();
	calc();
	disp();
}
void ip()
{
	int i;
	printf("Enter the no of memory slots ");
	scanf("%d"&n);
	if(n>10)
	{
		printf("MEMORY SLOTS SHOULD NOT BE MORE THAN 10");
		return;
	}
	printf("Enter the size of the slots\n");
	for(i=0;i<n;i++)
	scanf("%d",&res[i]);
	printf("Enter the no of processes ");
	scanf("%d",&m);
	if(n>10)
	{
		printf("NUMBER OF PROCESSES SHOULD NOT BE MORE THAN 10");
		return;
	}
	printf("Enter the size of the processes\n");
	for(i=0;i<m;i++)
		scanf("%d",&ip[i]);
}
void calc(){
	int index;
	int i,j,k;
	for(i=0;i<m;i++)
	{
		index=findmin();
		if(index!=-1)
		{
			all[i]=index;
			flag[index]=1;
		}
		else
		all[i]=-1;
		
	}
}

int findmin(){
	int min=9999999;
	int i,j=0;
	for(j=0;j<n;j++)
	{
		if(flag[j]==0 && res[i]<min)
		{
			min=res[i];
			i=j;
		}
	}
	if(i!=0)
	return i;
	else
	return -1;
	
}
