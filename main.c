#include <stdio.h>

int main()
{
    FILE *pText;
    char fileName[50] = "sample";
    int i = 0;
    int X[50]; // Storage for first column of text input
    int Y[50]; // Storage for second column of text input
    int Z[50]; // Storage for third column of text input


    //printf("Input file name: ");
    //fgets(fileName, sizeof(fileName), stdin);
    
    fileName[strcspn(fileName, "\n")] = 0;      // Remove newline at the end of string
    strcat(fileName, ".txt");
    //printf("%s", fileName); // Just a checker

    // Open and Read the file 
    pText = fopen(fileName, "r");

    if(pText == NULL) {

        printf("%s not found.\n", fileName);
        return 0;
        }

    printf("\nFile found!\n");
    
    while(fscanf(pText, "%d %d %d", &X[i], &Y[i], &Z[i]) == 3) {

        printf("X %d: %d\n", i, X[i]);
        printf("Y %d: %d\n", i, Y[i]);
        printf("Z %d: %d\n", i, Z[i]);

        i++;
    }

    fclose(pText);

    // add switch statements for different algos

    return 0;
}