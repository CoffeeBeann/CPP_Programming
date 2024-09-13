/***************************************************
Filename: hw35.c
Author: MIDN Ian Coffey (m261194)
Perform Row Functions
***************************************************/

// Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    // Variable Declarations
    char cmd[128];
    char c;
    int n;

    // Read In User Input
    scanf("%c%c%c%c%d", &c, &c ,&c, &c, &n);
    int* Nums = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &Nums[i]);
    }

    printf("cmd: ");

    while ((scanf("%s", cmd) == 1) && strcmp("quit", cmd) != 0) 
    {

        if (strcmp("show", cmd) == 0) 
        {
            for (int i = 0; i < n; i++) 
            {
                printf("[%d] ", i);

                for (int j = 0; j < Nums[i]; j++) 
                {
                    printf("*");
                }

                printf("\n");
            }
        }
        else if (strcmp(cmd,"swap") == 0) 
        {
            int num1, num2, temp;
            scanf("%d %d", &num1, &num2);

            temp = Nums[num1];
            Nums[num1] = Nums[num2];
            Nums[num2] = temp;

            
        }

        printf("cmd: ");
    }

    free(Nums);

    return 0;
}   