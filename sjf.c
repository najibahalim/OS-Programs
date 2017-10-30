#include<stdio.h>
void main(){
	int a[30],b[30],wt[30],tt[30],n;
	float awt=0,att=0;
	int i=0,j=0;
	printf("Enter the no of processes");
	scanf("%d",&n);
	printf("Enter the burst time of each proces:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nThe sorted Burst time :");
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
		printf("\t%d",b[i]);
	}
	printf("\nWaiting Time is :");
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		wt[i+1]=wt[i]+b[i];
	}
	for(i=0;i<n;i++)
	{
		printf("\t %d",wt[i]);
	}
	for(i=0;i<n;i++)
	{
		awt=wt[i]+awt;
		tt[i]=wt[i]+b[i];
		att=tt[i]+att;
	}
	printf("\nThe turnaround time of sorted process is ");
	for(i=0;i<n;i++)
	{
		printf("\t %d",tt[i]);
	}
	awt=awt/n;
	att=att/n;
	printf("\nThe average waiting time %f",awt);
	printf("\nThe average Turnaround time %f",att);
	
	getch();
}
