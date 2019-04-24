#include<stdio.h>
int at[3][10],bt[3][10],rt[3][10],priority[3][10],number[3];
int waiting_time,overall_time,turnaround_time;
int time_quantum = 10;
int n,remain,type;
int i,j,count;
void sorted(int queue)
{
	int max ,k,l,temp;
	for(k = 0;k<number[queue];k++)
	{
		max = priority[queue][k];		
		for( l=0;l<number[queue];l++)
			if(max>priority[queue][l])
			{
				temp=max;
				max = priority[queue][l];
				priority[queue][l]=temp;
			}	
	}
}
int main()
{
	
	printf("Enter Total Process:\t "); 
 	scanf("%d",&n);
	remain=n;
	for(i=0;i<3;i++) 
		number[i]=0;
	printf("Instructions - Time quantum over structure is 10\n1. CPU PROCESS Queue\n2. User process Queue\n3. IO Process Queue");
	for(i=0;i<n;i++)
	{	
		printf("Process no %d\nProcess Type:",i+1);
		scanf("%d",&type);type-=1;
		printf("Arrival Time :");
		scanf("%d",&at[type][i]);
		printf("Burst Time :");
		scanf("%d",&bt[type][i]);
		printf("Priority :");
		scanf("%d",&priority[type][i]);
		rt[type][i]=bt[type][i];
		number[type]++;		
	}
	for(i=0;i<3;i++)
	{
		sorted(i);
	}
	printf("\n\nProcess\t|Arr. Time|Priority|Completion Time|Turnaround Time|Waiting Time\n\n");
	for(overall_time = 0,count=0;remain!=0;)
	/*for(time=0,count=0;remain!=0;) 
  	{ 
    		if(rt[count]<=time_quantum && rt[count]>0) 
    		{ 
      			time+=rt[count]; 
     		 	rt[count]=0; 
      			flag=1; 
    	} 
    	else if(rt[count]>0) 
   	{ 
      		rt[count]-=time_quantum; 
      		time+=time_quantum; 
    	} 
    	if(rt[count]==0 && flag==1) 
    	{ 
      		remain--; 
      		printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      		wait_time+=time-at[count]-bt[count]; 
      		turnaround_time+=time-at[count]; 
      		flag=0; 
    	} 
    	if(count==n-1) 
      		count=0; 
    	else if(at[count+1]<=time) 
  	    		count++; 
    	else 
      		count=0; 
  	} 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  */
return 0;
	
}
void roundrobin(int quat,int time)
{
	int t_quat=4;
		if(rt[0][count]<=t_quat &&rt[0][count]<= quat && rt[0][count]>0) 
    		{ 
      			time+=rt[count]; 
     		 	rt[count]=0; 
      			flag=1; 
    	} 
    	else if(rt[count]>0) 
   	{ 
      		rt[count]-=time_quantum; 
      		time+=time_quantum; 
    	} 
    	if(rt[count]==0 && flag==1) 
    	{ 
      		remain--; 
      		printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      		wait_time+=time-at[count]-bt[count]; 
      		turnaround_time+=time-at[count]; 
      		flag=0; 
    	} 
    	if(count==n-1) 
      		count=0; 
    	else if(at[count+1]<=time) 
  	    		count++; 
    	else 
      		count=0; 
  	}
}

