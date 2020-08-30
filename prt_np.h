void PRT_NP()
{

    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter burst time and priority:\n ");
    for(i=0;i<n;++i){
        printf("\nP[%d]\n",i+1);
        printf("Burst time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    // sorting burst time,priority, process number in ascending order
    for (i=0;i<n;++i){
        pos=i;
        for(j=i+1;j<n;++j){
            if(pr[j]<pr[pos]){
                pos=j;
	        }

        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;//waiting time process 1 is 0
    //calculate waiting time

    for (i=1; i<n;++i){
        wt[i]=0;
        for(j=0;j<1;++j){
            wt[i]+=bt[j];
    	}
        total+=wt[i];
    }
    avg_wt=total/n;//avg waiting time
    total=0;
    printf("\nProcess\t          Burst time        \tPriority\tWaiting time\tTurnaround time");
    for(i=0;i<n;++i){
        tat[i]=bt[i]+wt[i];
        total=tat[i];
        printf("\nP[%d]\t\t        %d\t\t       %d\t\t%d\t\t%d",p[i],bt[i],pr[i],wt[i],tat[i]);
    }
    avg_tat=total/n;//avg turnaround time
    printf("\n\nAverage waiting time = %f",avg_wt);
    printf("\nAverage Turnaround time = %f", avg_tat); gantt_chart(n,p,bt,tat);
    gantt_chart(n,p,bt,tat);
}