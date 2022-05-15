#include "struct.h"

int comparator(const void *x, const void *y);
/*
 *  Contains fcfs algorithm takes in 2 parameters: 
 *  array of processes variables and number of processes
*/
void fcfs(process processes[], int numPro) {

    int waitingTime[numPro];
    int completionTime[numPro];
    int sortedAT[numPro];
    int totalWaitingTime = 0;
    process sortedProcesses[numPro];
    int counter[numPro];
    int numCounter = 0;
    int checker = 1;
    int i, k, c;
    
    // Get a copy of arrival time and process values
    for(i = 0; i < numPro; i++)
        sortedAT[i] = processes[i].arrivalTime;
    
    // Sort in ascending order based on arrival time
    qsort(sortedAT, numPro, sizeof(int), comparator);
    // printf("\nsAT: %d\n", sortedAT[0]);

    // Sort all corresponding process values
    for(i = 0; i < numPro; i++) {
        for(k = 0; k < numPro; k++) {
            
            for(c = 0; c < numCounter; c++) {   // Checks used IDs
                
                if(counter[c] == processes[k].ID) {
                    checker = 0;
                    break;
                }

                else checker = 1;
            }
            if(sortedAT[i] == processes[k].arrivalTime && checker) {
                sortedProcesses[i].arrivalTime = processes[k].arrivalTime;
                sortedProcesses[i].burstTime = processes[k].burstTime;
                sortedProcesses[i].ID = processes[k].ID;
 
                // printf("\nID: %d\t", sortedProcesses[i].ID );
                // printf("AT: %d\t", sortedProcesses[i].arrivalTime);
                // printf("BT: %d", sortedProcesses[i].burstTime);
                counter[numCounter] = sortedProcesses[i].ID;  
                numCounter++;  
                break;   
            }
        }
       
    }

    // Calculate completion time
    for(i = 0; i < numPro; i++) {

        if (i == 0 || sortedProcesses[i].arrivalTime > completionTime[i - 1]) {
            completionTime[i] = sortedProcesses[i].burstTime + sortedProcesses[i].arrivalTime;
            //printf("\nIF: %d BT + %d AT\n", sortedProcesses[i].burstTime, sortedProcesses[i].arrivalTime);
        }

        else {
            completionTime[i] = completionTime[i - 1] + sortedProcesses[i].burstTime;
            //printf("\nELSE: %d CT-1 + %d BT\n", completionTime[i - 1], sortedProcesses[i].burstTime);
        }

        //printf("\nCT: %d\t", completionTime[i]);
       
    }
    // Calculate waiting time
    for(i = 0; i < numPro; i++) {
        
        waitingTime[i] = (completionTime[i] - sortedProcesses[i].arrivalTime) - sortedProcesses[i].burstTime;
        //printf("\nWaiting Time %d: %d", i + 1, waitingTime[i]);

        totalWaitingTime += waitingTime[i];
    }
    

    // Print final values
    for(i = 0; i < numPro; i++) {

        if(i == 0)
            printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", sortedProcesses[i].ID, 0, completionTime[i], waitingTime[i]);
        else
            printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", sortedProcesses[i].ID, completionTime[i - 1], completionTime[i], waitingTime[i]);
    }

    printf("Average waiting time: %.1f", (float) totalWaitingTime / numPro);
}      

