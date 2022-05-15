#include "struct.h"

void srtf(process processes[], int numPro)
{
    int i, j;
    int time, proCount = 0, smallest, prevSmallest = -1, aveWaitingTime, totalWaitingTime = 0;
    int waitingTime[MAX], temp[MAX];
    int start[MAX], end[MAX];

    // Copy burst time to value holder
    for (i = 0; i < numPro; i++)
    {
        temp[i] = processes[i].burstTime;
    }

    for (time = 0; proCount < numPro; time++)
    {
        smallest = numPro - 2;
        // Find smallest remaining time
        for (i = 0; i < numPro; i++)
        {
            if (processes[i].arrivalTime <= time && processes[i].burstTime < processes[smallest].burstTime && processes[i].burstTime > 0)
            {
                smallest = i;
            }
        }

        if (smallest != prevSmallest)
        {
            start[smallest] = time;
        }

        processes[smallest].burstTime--;

        if (processes[smallest].burstTime == 0) // Process is done
        {
            proCount++;
            end[smallest] = time + 1;
            waitingTime[smallest] = end[smallest] - temp[smallest] - processes[smallest].arrivalTime;
            totalWaitingTime += waitingTime[smallest];
        }
        prevSmallest = smallest;
    }
    aveWaitingTime = totalWaitingTime / numPro;

    for (i = 0; i < numPro; i++)
    {
        printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", processes[i].ID, start[i], end[i], waitingTime[i]);
    }
    printf("Average Waiting Time: %d\n", aveWaitingTime);
}