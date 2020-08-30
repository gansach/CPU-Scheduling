void PRT_P(){
	int at[20],pr[20],bt[20],rt[20],wt[20],tat[20],p[20],i,j,count=0,time,n,smallest,end_time;
	float avg_tt=0,avg_wt=0;
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	printf("\nEnter the burst time , arrival time , priority of the processes: ");
	for(i=0;i<n;++i){
		printf("\nProcess %d",i+1);
		printf("\nEnter the arrival time: ");
		scanf("%d",&at[i]);
		printf("\nEnter the burst time: ");
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
		printf("\nEnter the priority of the process: ");
		scanf("%d",&p[i]);
		pr[i]=i+1;
	}
	p[19]=-1;
	printf("\nGANTT CHART\n");
	for(time=0;count!=n;++time){
		if(time==0){
			printf(" 0 ");
		}
		smallest=19;
		for(i=0;i<n;++i){   //searching for the process with highest priority least burst time
			if(at[i]<=time && p[i]>p[smallest] && rt[i]>0){
				smallest=i;
			}
		}
		printf(" -> P%d <- %d " ,pr[smallest],time+1);
		--rt[smallest];
		if(rt[smallest]==0){   //process has completed
			++count; //no. of processes completed
			end_time=time+1;//time at which the process has completed execution
			tat[smallest]=end_time-at[smallest];//calculate turnaround time
			wt[smallest]=tat[smallest]-bt[smallest];//calculate waiting time
			avg_tt+=tat[smallest];
			avg_wt+=wt[smallest];
		}
	}
	printf("\nProcess\tArrival time\tBurst time\tPriority\tWaiting time\tTurnaround time");
	for(i=0;i<n;++i){
		printf("\n\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],p[i],wt[i],tat[i]);
	}
	avg_tt/=n;
	avg_wt/=n;
	printf("\n\nAverage waiting time: %f",avg_wt);
	printf("\n\nAverage turnaround time: %f",avg_tt);
}
