#include <stdio.h>
#include <string.h>
#include "fcfs.c"
#include "sjf.c"
#include "srtf.c"
#include "struct.h"

int main()
{
    FILE *pText;
    char fileName[MAX] = "sample";

    int i = 0;
    int k = 0;

    int X[MAX]; // Storage for first column of text input
    int Y[MAX]; // Storage for second column of text input
    int Z[MAX]; // Storage for third column of text input

    process processes[MAX];

    // printf("Input file name: ");
    // fgets(fileName, sizeof(fileName), stdin);

    fileName[strcspn(fileName, "\n")] = 0; // Remove newline at the end of string
    strcat(fileName, ".txt");
    // printf("%s", fileName); // Just a checker

    // Open and Read the file
    pText = fopen(fileName, "r");

    if (pText == NULL)
    {

        printf("%s not found.\n", fileName);
        return 0;
    }

    // printf("\nFile found!\n");

    while (fscanf(pText, "%d %d %d", &X[i], &Y[i], &Z[i]) == 3)
    {

        // printf("X %d: %d\n", i, X[i]);
        // printf("Y %d: %d\n", i, Y7[i]);
        // printf("Z %d: %d\n", i, Z[i]);

        if (i > 0)
        {
            processes[k].ID = X[i];
            processes[k].arrivalTime = Y[i];
            processes[k].burstTime = Z[i];

            //   printf("ID: %d\t", processes[k].ID );
            //   printf("AT: %d\t", processes[k].arrivalTime);
            //   printf("BT: %d\n", processes[k].burstTime);

            k++;
        }

        i++;
    }

    fclose(pText);

    // add switch statements for different algos

    switch (X[0])
    {
    case 0: // First-Come First-Serve (FCFS)
        fcfs(processes, Y[0]);
        break;
    case 1: // Shortest-Job First (SJF)
        // sjf(processes, Y[0]);
        break;
    case 2: // Shortest-Remaining-Time-First (SRTF)
        // srtf(processes, Y[0]);
        break;
    case 3: // Round-Robin (RR)

        break;
    }

    return 0;
}