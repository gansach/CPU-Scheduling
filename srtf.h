void SRTF(){

    int at[10],bt[10],rt[10],p[10];
    int wt[10], tat[10],time;
    int i, smallest, count=0, end_time=0,n;
    double avg_wt=0, avg_tt=0;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n; ++i) {
        printf("\nProcess %d",i+1);
        printf("\nEnter the arrival time: ");
        scanf("%d",&at[i]);
        printf("\nEnter the burst time: ");
        scanf("%d", &bt[i]);
        rt[i]=bt[i];
        p[i]=i+1;
    }
    bt[9]=9999;
    rt[9]=9999;
    printf("\nGANTT CHART\n");
    for(time=0; count!=n;++time) {
        smallest=9;
        if(time==0){
            printf(" 0");
        }
        for(i=0;i<n;++i){	//search for the process with least remaining time
            if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0){
                smallest=i;
            }
        }
        printf(" -> P%d <- %d ", p[smallest], time+1);
        --rt[smallest]; // 1 second of smallest process is executed
        if (rt[smallest]==0) {//the smallest process has just completed execution 
            ++count;         // count of number of sompleted process is incremented
            end_time=time+1; //time at which process has completed execution
            tat[smallest]=end_time-at[smallest]; //calculate turnaround time
            wt[smallest]=tat[smallest]-bt[smallest]; //calculate writing time
            avg_wt+=wt[smallest];
            avg_tt+= tat[smallest];
        }
    }
    printf("\nProcess\tBurst time\tArrival time\tWaiting time\tturnaround time"); 
    for (i=0;i<n;++i) { 
        printf("\n\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1, bt[i],at[i],wt[i],tat[i]);
    } 
    avg_wt/=n;
    avg_tt/=n; 
    printf("\n\nAverage waiting time: %f", avg_wt); 
    printf("\nAverage turnaround time: %f", avg_tt);
}