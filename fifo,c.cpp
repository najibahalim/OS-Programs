#include<stdio.h>
int cache[3]={-99,-99,-99},memory[100];
int main(){
	int i,j,k,n,hit=0,miss=0,h,pointer=0,flag,used[3]={0};
	printf("Enter the size of input String ");
	scanf("%d",&n);
	printf("Enter the input String\n");
	for(i=0;i<n;i++)
		scanf("%d",&memory[i]);
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<3;j++)
		{
			if(cache[j]==memory[i])
			{
				hit++;
				used[j]++;
				printf("Status of Cache::");
				for(h=0;h<3;h++)
				printf("%d ",cache[h]);
				printf("HIT\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			
			miss++;
			cache[pointer]=memory[i];
			used[pointer]=0;
			printf("Status of Cache:: ");
			for(h=0;h<3;h++)
			printf("%d ",cache[h]);
			printf("MISS\n");
			pointer++;
			pointer%=3;
		}
	
	}
	printf("\nHits=%d Miss=%d hit/miss=%.2f ",hit,miss,(float)hit/miss);
	return 0;
	
}
