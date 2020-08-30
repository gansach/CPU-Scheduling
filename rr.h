void RR(){
    int count,j,n,time,remain,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,p[10],at[10],bt[10],rt[10],wt[10],tat[10];
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    remain=n;
    for(count=0;count<n;++count){
        printf("\nEnter arrival time for process with process number %d  ",count+1);
    	scanf("%d",&at[count]);
        printf("\nEnter burst time for process with process number %d  ",count+1);
		scanf("%d",&bt[count]);
    	rt[count]=bt[count];
    	p[count]=count+1;
    	
    	
    }
    printf("\nEnter time quantum:\t");
    scanf("%d",&time_quantum);
    printf("\nGANTT CHART\n");
    for(time=0,count=0;remain!=0;){
    		if(time==0){
    				printf(" 0");
			}
			if(rt[count]<=time_quantum && rt[count]>0){
					time+=rt[count];
					printf(" -> P%d <- %d",p[count],time);
					rt[count]=0;
					flag=1;
			}
			else if(rt[count]>0){
					rt[count]-=time_quantum;
					time+=time_quantum;
					printf(" -> p%d <- %d",p[count],time);
			}
			if(rt[count]==0 && flag==1){
				--remain;
				wt[count]=time-at[count]-bt[count];
				tat[count]=time-at[count];
				wait_time+=time-at[count]-bt[count];
				turnaround_time+=time-at[count];
				flag=0;
			}
			if(count==n-1){
				count =0;
			}
			else if (at[count+1]<=time){
				count++;
			}
			else{
				count=0;
			}
	
	}
	printf("\n\nProcess\t|Arrival time\t|Burst time\t|Turnaround time\t|Waiting time\n\n");
	for(count=0;count<n;count++){
				printf("\nP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",p[count],at[count],bt[count],tat[count],wt[count]);
			}
			printf("\nAverage waiting time = %f\n" ,wait_time*1.0/n);
			printf("\nAverage Turnaround time = %f" , turnaround_time*1.0/n);
			return 0;
	}