
#include <stdio.h>
#include <unistd.h>

void main()
{
    int original[16], new[20];
    int i, j, k, ones_count, size;
    printf("Enter Number of bits(max : 16) :");
    scanf("%d", &size);
    printf("Enter the Number  in the form of 0s and 1s :");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &original[i]);
    }
    i = 0;
    j = 0;
    ones_count = 1;
    while (i < size)
    {
        if (original[i] == 1) // if 1 is detected
        {
            new[j] = original[i];                                                //array new[pos] <- 1
            for (k = i + 1; original[k] == 1 && k < size && ones_count < 6; k++) // loop active while  next element in original[] is 1 and ones_count less than 5
            {
                j++;                                         // array new[] subscript incremented
                new[j] = original[k];                        //array new[pos] <- 1
                ones_count++;                                // 1's count incremented
                if (ones_count == 5 && original[k + 1] == 1) // checking 5 count of 1s and making sure next element is 1, and inserting a 0 at next position in array new[]
                {
                    j++; // array new[] subscript incremented to insert 0
                    new[j] = 0;
                    ones_count = 0; // reinitialize the one_count
                }
                i = k; //moving to next element
            }
        }
        else //when original[i] == 0 ,it is directly inserted in new array
        {
            new[j] = original[i];
        }
        i++;
        j++;
    }
    printf("\nNew Frame :");
    for (i = 0; i < j; i++)
    {
        printf("%d", new[i]);
    }
    printf("\n");
    getchar();
}
