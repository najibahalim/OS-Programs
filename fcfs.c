#include<stdio.h>
void main(){
	int bt[10]={0},wt[10]={0},tt[10]={0},n,i,mark;
	float sum1=0,sum2=0;
	printf("Enter the no of processes");
	scanf("%d",&n);
	printf("Enter the burst time of each process:");
	for(i=0;i<n;i++)
	scanf("%d",&bt[i]);
	wt[0]=0;
	tt[0]=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tt[i]=tt[i-1]+bt[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\n",wt[i],tt[i]);
		sum1=sum1+wt[i];
		sum2=sum2+tt[i];
	}
	sum1/=n;
	sum2/=n;
	printf("avg wt is %f\n",sum1);
	printf("avg tt is %f\n",sum2);
	getch();
}
