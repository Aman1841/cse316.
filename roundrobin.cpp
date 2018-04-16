#include<stdio.h>
#include<conio.h>
int main()
 {
   int x,n; //n is number of process
   int p[10];  //p is process
   int prior[10];  //prior is process priority
   int burst[10];  //burst is process burst time
   int wait[10];   //wait is wait time
   int t[10];   // t is turnaround time
   int await;     //await is average waiting time
   int avg_turn; //avg_turn is average turnaround time
   int i;      
   int at[10]; //at is arrival time
   int tq;  //tq is time qunatum
 
  
 
 
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("Enter time quantum");
   scanf("%d",&tq);
   printf("\n\t Enter burst time : time priorities : Arrival time  \n");
 
   for(i=0;i<n;i++)
    {
      
      printf("\n Process %d ",i+1);
      
      scanf("%d %d %d",&burst[i],&prior[i],&at[i]);
	  p[i]=i+1;
    }
 
//Sorting according to their  priority
int j;
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(prior[i]<prior[j])
       {
     x=prior[i];
     prior[i]=prior[j];
     prior[j]=x;
     x=burst[i];
     burst[i]=burst[j];
     burst[j]=x;
     x=p[i];
     p[i]=p[j];
     p[j]=x;
      }
      
   }
}
wait[0]=0;
await=0;
t[0]=burst[0];
avg_turn=t[0];
for(i=1;i<n;i++)
 {
 	if(tq<n || tq>n) {
	 
   wait[i]=t[i-1];
   await+=wait[i];
   t[i]=wait[i]+burst[i];
   avg_turn+=t[i];
	 }
 }
 
 //gantt chartt
 printf("\n");
 printf("\ngantt-------------- chart\n");
 for(i=0;i<n;i++)
 {
 	printf("P %d ",p[i]);
 }
// process
 
printf("\n\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<n;i++){
printf("\n  %d",p[i]); printf("\t\t %d",burst[i]); printf("\t\t %d",wait[i]); printf("\t\t %d",t[i]); printf("\t\t %d",prior[i]); printf("\t\t %d",at[i]);

}
await/=n;
avg_turn/=n;
printf("\n Average Wait Time : %d ",await);
printf("\n Average Turn Around Time : %d",avg_turn);
getch();
}
