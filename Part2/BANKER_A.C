#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
int avail[10],max[10][10],alloc[10][10],need[10][10],completed[10]={0};
int p,r,i,j,process,count = 0,result[10]={0};
clrscr();
printf("\n\n total no. of process is : ");
scanf("%d",&p);
printf("\n\nthe total types of resources : ");
scanf("%d",&r);
printf("\n\n enter the allocaton matrix\n");
for(i=0; i<p;i++){
	printf("for process %d :  ",(i+1));
	for(j=0;j<r;j++)
		scanf("%d",&alloc[i][j]);

}
printf("\n\n enter the maximum requriments for each process \n");

for(i=0; i<p;i++){
	printf("for process %d :  ",(i+1));
	for(j=0;j<r;j++)
		scanf("%d",&max[i][j]);

}
	printf("\nenter the available resources\n");

for(i=0;i<r;i++){
	scanf("%d",&avail[i]);
}
/* calculation of need matrix */
for(i = 0 ; i<p ; i++){
	for(j = 0; j<r ; j++){
		need[i][j]= abs(alloc[i][j] - max[i][j]);
	}
}
	process = -1; printf("\n\n");
	printf("allocation  \t\t max \t\t need\n");

do{
 /* print allocation and max matrix
 for(i=0 ; i< p; i++)
 {
	for(j =0;j<r ; j++ ){
	 printf("%d ",alloc[i][j]);
	}
	for(j =0;j<r ; j++ ){
	 printf("%d ",max[i][j]);
	}
	for(j =0;j<r ; j++ ){
	 printf("%d ",need[i][j]);
	}
	printf("\n");
 } */
 process = -1;
 for(i = 0;i<p;i++)
 {
	if(completed[i]==0)
	{
		process = i;
		for(j = 0 ; j<r ; j++)
		{
			if(avail[j] < need[i][j])
			{
				process = -1;
				break;
			}
		}
	}
       if(process !=-1)
       {
	break;
       }
 } if(process !=-1){
   result[count] = process + 1;
   for(i = 0; i<r ; i++){
	avail[i] += alloc[process][i];

   }
   completed[process] = 1;
   count++;
   }


}while(count != p && process!=-1);
 if(count == p)
 {
	printf("the given set of process have safety sequence as follows :\n");
	for(i=0;i<p;i++)
	printf("%d -> ", result[i]);

 }
 else{
 printf("there is no safety sequence ");
 }




getch();
}