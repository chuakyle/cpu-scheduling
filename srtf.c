#include "struct.h"

void srtf(process processes[], int numPro)
{
    int i;
    int time, smallest, proCount = 0;
    int hold[MAX], end[MAX], waitingTime[MAX];
    int totalWaitingTime = 0;
    double aveWaitingTime = 0;

    // Copy burst time to value holder
    for (i = 0; i < numPro; i++)
    {
        hold[i] = processes[i].burstTime;
    }

    for (time = 0; proCount != numPro; time++)
    {
        smallest = numPro - 1;
        // Find shortest remaining time
        for (i = 0; i < numPro; i++)
        {
            if (processes[i].arrivalTime <= time && processes[i].burstTime < processes[smallest].burstTime && processes[i].burstTime > 0) // if found new shortest remaining time
            {
                smallest = i;
            }
        }
        processes[smallest].burstTime--;
        if (processes[smallest].burstTime == 0) // if process is done
        {
            proCount++;                               // process counter
            end[smallest] = time + 1;                 // end time
            waitingTime[smallest] = totalWaitingTime; // waiting time
            totalWaitingTime = totalWaitingTime + end[smallest] - processes[smallest].arrivalTime - hold[smallest];
        }
    }
    aveWaitingTime = totalWaitingTime / numPro;

    // printf("nnAverage Waiting Time:t%lfn", average_waiting_time);
    // printf("Average Turnaround Time:t%lfn", average_turnaround_time);
}