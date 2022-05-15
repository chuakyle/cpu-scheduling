#include "struct.h"

void sjf(process processes[], int numPro)
{
    int i, j;
    int pos;
    int temp[1];
    int waitingTime[MAX], start[MAX], end[MAX];
    int totalWaitingTime = 0;
    int aveWaitingTime;

    // Sort burst time in ascending order
    for (i = 0; i < numPro; i++)
    {
        pos = i;
        for (j = i + 1; j < numPro; j++)
        {
            if (processes[j].burstTime < processes[pos].burstTime)
                pos = j;
        }

        temp[0] = processes[i].ID;
        temp[1] = processes[i].burstTime;
        processes[i].ID = processes[pos].ID;
        processes[i].burstTime = processes[pos].burstTime;
        processes[pos].ID = temp[0];
        processes[pos].burstTime = temp[1];
    }
    waitingTime[0] = 0;
    start[0] = 0;
    end[0] = processes[0].burstTime;

    // Calculate completion and waiting time
    for (i = 1; i < numPro; i++)
    {
        start[i] = end[i - 1];
        end[i] = start[i] + processes[i].burstTime;
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;

        totalWaitingTime += waitingTime[i];
    }
    aveWaitingTime = totalWaitingTime / numPro;

    // print output
    for (i = 0; i < numPro; i++)
    {
        printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", processes[i].ID, start[i], end[i], waitingTime[i]);
    }
    printf("Average Waiting Time: %d", aveWaitingTime);
}