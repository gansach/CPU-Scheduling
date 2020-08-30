void FCFS() {
    int bt[20], wt[20], tat[20], p[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the burst time: \n");
    for(i = 0; i < n; ++i){
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i]=i+1;        
    }
    wt[0]=0;
    for(i=1;i<n;++i){
        wt[i]=wt[i-1]+bt[i-1];
        total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\nProcess\t Burst Time  \tWaiting Time\t Turnaround Time\t Response Time");
    for(i=0;i<n;++i){
        tat[i]=wt[i]+bt[i];
        total+=bt[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d\t\t\t%d", p[i], bt[i], wt[i], tat[i], wt[i]);
    }
    avg_tat=(float)total/n;
    printf("\n|nAverage waiting time = %f", avg_wt);
    printf("\nAverage turnaround time = %f\n", avg_tat);
    gantt_chart(n, p, bt, tat);

}