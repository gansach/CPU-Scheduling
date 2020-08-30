#include <stdio.h>
#include "gantt.h"
#include "fcfs.h"
#include "sjf.h"
#include "srtf.h"
#include "prt_p.h"
#include "prt_np.h"
#include "rr.h"


int main(void) 
{
    int ch, ch2, n;

    do 
    {
        printf("\n\n Choose Scheduling Algorithm:");
        printf("\n 1. FCFS");
        printf("\n 2. SJF (Pre-emptive & Non Pre-emptive)");
        printf("\n 3. Priority Scheduling (Pre-emptive & Non Pre-emptive)");
        printf("\n 4. Round Robin");
        printf("\n 5. Exit\n Select : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                FCFS();
                break;
            case 2:
                printf("\nEnter scheduling mode:");
                printf("\n1. Pre-emptive");
                printf("\n2. Non Pre-emptive");
                printf("\nSELECT : ");
                scanf("%d", &ch2);
                if (ch2 == 1) {
                    SRTF();
                } else if (ch2 == 2) {
                    SJF();
                }
                break;
            case 3:
                printf("\nEnter scheduling mode:");
                printf("\n1. Pre-emptive");
                printf("\n2. Non Pre-emptive");
                printf("\nSELECT : ");
                scanf("%d", &ch2);
                if (ch2 == 1) {
                    PRT_P();
                } else if (ch2 == 2) {
                    PRT_NP();
                }
                break;
            case 4:
                RR();
                break;
            case 5:
                exit(0);
        }
    } 
    while (ch != 5);

    return 0;
}