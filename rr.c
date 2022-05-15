#include "struct.h"

int comparator(const void *x, const void *y);
/*
 *  Contains rr algorithm takes in 3 parameters: 
 *  array of processes variables, number of processes and time slice
*/

void rr(process processes[], int numPro, int timeSlice) {

    int allProcessesNotDone = 1;
    int waitingTime[numPro];
    int totalWaitingTime = 0;
    int copyBT[numPro];
    int time = 0;

    process sortedProcesses[numPro];
    int counter[numPro];
    int sortedAT[numPro];
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
 
                printf("\nID: %d\t", sortedProcesses[i].ID );
                printf("AT: %d\t", sortedProcesses[i].arrivalTime);
                printf("BT: %d", sortedProcesses[i].burstTime);
                counter[numCounter] = sortedProcesses[i].ID;  
                numCounter++;  
                break;   
            }
        }
       
    }

    for(i = 0; i < numPro; i++)
        copyBT[i] = sortedProcesses[i].burstTime;

    // Calculate waiting time    
    do
    {
        for(i = 0; i < numPro; i++) {

            printf("\n copyBT[%d]: %d", i, copyBT[i]);
            if(copyBT[i] > 0) { // Check if there are remaining burst time

                printf("\nAT: %d <= time: %d ", sortedProcesses[i].arrivalTime, time);

                if(time >= sortedProcesses[i].arrivalTime){ // Check if process have arrived at current time

                    if(copyBT[i] > timeSlice) {
                      printf("\n if check");  
                      time += timeSlice;       
                      copyBT[i] -= timeSlice; 
                    }

                    else {
                        printf("\n else check");  
                        time += copyBT[i];                                      
                        waitingTime[i] = time  -  sortedProcesses[i].arrivalTime - sortedProcesses[i].burstTime;   
                        totalWaitingTime += waitingTime[i];
                        printf("\nWT[%d]: %d = time: %d - AT: %d - BT - %d", i, waitingTime[i], time, sortedProcesses[i].arrivalTime, sortedProcesses[i].burstTime);
                        copyBT[i] = 0;
                        break;
                    }
                }
            }

            
        }
       
        numCounter = 0; // reuse counter variable  

        // Check if all processes are done
        for(i = 0; i < numPro; i++) {   
            
            // s
            if(copyBT[i] == 0)
                numCounter++;
        }
        //printf("\nnumCounter: %d", numCounter);
        if(numCounter == numPro)
            allProcessesNotDone = 0;
        else
            allProcessesNotDone = 1;

    } while (allProcessesNotDone);

    printf("\nAverage waiting time: %.1f", (float) totalWaitingTime / numPro);
    
}