#include<stdio.h>
int at[3][10],bt[3][10],rt[3][10],priority[3][10],number[3];
int waiting_time=0,overall_time=0,turnaround_time=0;
int time_quantum = 10;
int n,remain,type;
int i,j,flag=0,count =0 ,t_quat=4,RRnumber=0,fcfsnumber=0,fcfsnu=0,RRnu=0,prioritynumber=0,priornu;
void sorted(int queue)
{
	int maxa,maxb,maxp ,k,l,temp;
	for(k = 0;k<number[queue];k++)
	{
		maxp = priority[queue][k];
		maxb = bt[queue][k];
		maxa = at[queue][k];		
		for( l=0;l<number[queue];l++)
		{
			if(maxp>priority[queue][l])
			{
				temp=maxp;
				maxp = priority[queue][l];
				priority[queue][l]=temp;
				temp = maxb;
				maxb = bt[queue][l];
				bt[queue][l]=temp;
				temp=maxa;
				maxa=at[queue][l];
				at[queue][l]=temp;
			}
		}
		at[queue][k]=maxa;
		bt[queue][k]=maxb;
		priority[queue][k]=maxp;
		rt[queue][k]=bt[queue][k];
		}
	}
}
int main()
{
	
	printf("Enter Total Process:\t "); 
 	scanf("%d",&n);
	remain=n;
	for(i=0;i<3;i++) 
	{
		number[i]=0;
	}
	printf("Instructions - Time quantum over structure is 10\n1. CPU PROCESS Queue\n2. User process Queue\n3. IO Process Queue");
	printf("\nqueue list %d %d %d",number[0],number[1],number[2]);
	for(i=0;i<n;i++)
	{	
		printf("\nProcess no %d\nProcess Type:",i+1);
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
	printf("\nqueue list %d %d %d",number[0],number[1],number[2]);
	printf("\n\nProcess\t|\tArr. Time\t|\tPriority\t|\tCompletion Time\t|\tTurnaround Time\t|\tWaiting Time\n\n");
	priornu = number[1];
	sorted(1);
	//sortforfcfs();
	for(overall_time = 0;remain!=0;)
	{
		//RRnumber=roundRobin(time_quantum);
		
		prioritynumber=prioritysch(time_quantum);
		
		//fcfsnumber = FCFS(time_quantum);
	}
	/*
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  */
return 0;
	
}
void sortforfcfs()
{
	int temp,mina,minb,minp;
	for(i=0;i<number[2]-1;i++)
	{
		mina=at[2][i];
		minb = bt[2][i];
		minp=priority[2][i];
		for(j=0;j<number[2];j++)
		{
			if(mina>at[2][j])
			{
				temp=mina;
				mina = at[2][j];
				at[2][j]=temp;
				temp = minb;
				minb = bt[2][j];
				bt[2][j]=temp;
				temp=minp;
				minp=priority[2][j];
				priority[2][j]=temp;
			}
		}
		at[2][i]=mina;
		bt[2][i]=minb;
		priority[2][j]=minp;
		rt[2][i]=bt[2][i];
	}
}
int prioritysch(int quat)
{
	
	for(count = prioritynumber;priornu!=0&&quat>0;)
	{
		if(rt[1][count]<=quat && rt[1][count]>0)
		{
			overall_time+=rt[1][count];
			quat-=rt[1][count];
			rt[1][count]=0;
			flag=1;
		}
		else if(rt[1][count]>0)
		{
			overall_time+=quat;
			rt[1][count]-=quat;
			quat =0;
		}
		if(rt[1][count]==0 && flag==1) 
    		{ 
			priornu--;
			remain--; 
      			print_comp(1,overall_time,count);
      			flag=0;
			count++; 
    		}

		if(at[1][count]<=overall_time) 
  	    		count++;
		if(count>number[1])
			count=0;
	}
	return count;
}
int FCFS(int quat)
{
	for(count = fcfsnumber;number[2]!=0&&quat>0;)
	{
		if(rt[2][count]<=quat && rt[2][count]>0)
		{
			overall_time+=rt[2][count];
			quat-=rt[2][count];
			rt[2][count]=0;
			flag=1;
		}
		else if(rt[2][count]>0)
		{
			overall_time+=quat;
			rt[2][count]-=quat;
			quat =0;
		}
		if(rt[2][count]==0 && flag==1) 
    		{ 
      			number[2]--;
			remain--; 
      			print_comp(2,overall_time,count);
      			flag=0;
			count++; 
    		}

		if(at[2][count]<=overall_time) 
  	    		count++;
		if(count>number[2])
			count=0;
	}
	return count;
}
int roundRobin(int quat)
{
	for(count=RRnumber,t_quat=4;number[0]!=0 && quat>0;)
	{
		if(t_quat>quat)
		{
			t_quat=quat;
		}
		if(rt[0][count]<=t_quat && rt[0][count]>0) 
    		{ 
      			overall_time+=rt[0][count]; 
			quat-=t_quat;
    			rt[0][count]=0; 
    			flag=1; 
    		}	 
    		else if(rt[0][count]>0) 
   		{ 
      			rt[0][count]-=t_quat; 
      			overall_time+=t_quat; 
			quat-=t_quat;
    		}	 	
    		if(rt[0][count]==0 && flag==1) 
    		{ 
      			number[0]--;
			remain--; 
      			print_comp(0,overall_time,count);
      			flag=0; 
    		}	 
    		if(count==number[0]) 
      			count=0; 
    		else if(at[0][count+1]<=overall_time) 
  	    		count++; 
    		else 
      			count=0;
		
	 
  	}
	 
return count;
}
void print_comp(int type,int time,int c)
{
	printf("\nP[%d%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",type,c+1,at[type][c],priority[type][c],time,time-at[type][c],time-at[type][c]-bt[type][c]); 
      			waiting_time+=time-at[type][c]-bt[type][c]; 
      			turnaround_time+=time-at[type][c];
}

