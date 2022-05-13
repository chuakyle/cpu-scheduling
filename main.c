#include <stdio.h>

int main()
{
    FILE *pText;
    char fileName[50] = "sample";
    int i = 0;
    int numAlgo[50];
    int numPro[50];
    int timeSlice[50];


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
    
    while(fscanf(pText, "%d %d %d", &numAlgo[i], &numPro[i], &timeSlice[i]) == 3) {

        printf("Algo %d: %d\n", i, numAlgo[i]);
        printf("numpro %d: %d\n", i, numPro[i]);
        printf("timeslice %d: %d\n", i, timeSlice[i]);

        i++;
    }

    fclose(pText);

    // add switch statements for different algos

    return 0;
}