#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Set a constant block value
#define BLOCK 512

int main(int argc, char *argv[])
{

    //Exit the prog when there are not 2 argument count.
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //Check the input file whether empty or not.
    char *inputName = argv[1];
    FILE *inputFile = fopen(inputName, "r");
    if (inputFile == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    unsigned char *buffer = malloc(BLOCK);
    FILE *outputFile = NULL;
    char fileName[8];
    int fileNum = 0;
    bool newImg = false;
    
    while (fread(buffer, BLOCK, 1, inputFile) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (newImg == false)
            {
                newImg = true;
            }
            else
            {
                fclose(outputFile);
            }
            
            sprintf(fileName, "%03i.jpg", fileNum);
            outputFile = fopen(fileName, "w");
            fileNum++;
        }
        if (newImg == true)
        {
            fwrite(buffer, BLOCK, 1, outputFile);
        }
    }
    
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}