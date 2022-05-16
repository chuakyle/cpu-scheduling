#include "struct.h"

void sjf(process processes[], int numPro)
{
    int i, j, flag;
    int pos, time = 0, proCount = 0;
    int hold[2];
    int waitingTime[MAX], start[MAX], end[MAX], id[MAX];
    float totalWaitingTime = 0;
    float aveWaitingTime;

    // Sort burst time
    while (proCount < numPro)
    {
        for (i = 0; i < numPro; i++)
        {
            flag = 0;
            pos = i;
            for (j = i + 1; j < numPro; j++)
            {
                if (processes[j].arrivalTime <= time && processes[j].burstTime < processes[pos].burstTime && processes[j].burstTime > 0 && processes[i].burstTime > 0)
                {
                    pos = j;
                    flag = 1;
                }
            }
            if (flag)
            {
                hold[0] = processes[i].ID;
                hold[1] = processes[i].arrivalTime;
                hold[2] = processes[i].burstTime;
                processes[i].ID = processes[pos].ID;
                processes[i].arrivalTime = processes[pos].arrivalTime;
                processes[i].burstTime = processes[pos].burstTime;
                processes[pos].ID = hold[0];
                processes[pos].arrivalTime = hold[1];
                processes[pos].burstTime = hold[2];
            }
        }

        // Calculate completion and waiting time
        if (processes[proCount].arrivalTime <= time)
        {
            id[proCount] = processes[proCount].ID;
            start[proCount] = time;
            end[proCount] = start[proCount] + processes[proCount].burstTime;
            waitingTime[proCount] = start[proCount] - processes[proCount].arrivalTime;
            time += processes[proCount].burstTime;
            processes[proCount].burstTime = 0;

            totalWaitingTime = totalWaitingTime + waitingTime[proCount];
            proCount++;
        }
        else
        {
            time++;
        }
    }
    aveWaitingTime = totalWaitingTime / numPro;

    // print output
    for (i = 0; i < numPro; i++)
    {
        printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", id[i], start[i], end[i], waitingTime[i]);
    }
    printf("Average Waiting Time: %.1f\n", aveWaitingTime);
}