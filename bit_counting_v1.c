/*
@Author Thomas A.K.L.
*/

#include <stdio.h>
#include <unistd.h>

void main()
{
    int numbers[16];
    int i, zeros_count, ones_count, n;
    printf("Enter Number of bits(max : 16) :");
    scanf("%d", &n);
    printf("Enter the Number  in the form of 0s and 1s :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    ones_count = 0;
    zeros_count = 0;
    for (i = 0; i < n; i++)
    {

        if (numbers[i] == 0)
        {
            zeros_count++;
        }
        else if (numbers[i] == 1)
        {
            ones_count++;
        }
    }
    printf("Number of 1's  : %d\n", ones_count);
    printf("Number of 0's  : %d\n", zeros_count);

    getchar();
}
