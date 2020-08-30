void gantt_chart(int n, int p[20], int bt[20], int tat[20]) {
    int i, j;
    printf("\nGANTT CHART\n");
    //print top bar
    for (i = 0; i < n; ++i) {
        for (j = 0; j < bt[i]; ++j) {
            printf("--");
        }
        printf("  ");
    }
    printf("\n|");
    //print the process in the middle
    for(i = 0; i< n; ++i) {
        for(j = 0; j < bt[i] - 1; ++j) {
            printf(" ");
        }
        printf("P%d", p[i]);
        for(j =0; j < bt[i]-1;++j) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    //print bottom bar
    for(i =0; i <n;++i) {
        for(j=0;j<bt[i];++j){
            printf("--");
        }
        printf(" ");
    }
    printf("\n");
    // print the time line
    printf("\n0");
    for(i=0;i<n;++i) {
        for(j=0;j<bt[i];++j){
            printf("  ");
        }
        printf("%d", tat[i]);
    }
    printf("\n");
}