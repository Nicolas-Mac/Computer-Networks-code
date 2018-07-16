/*
@Author Thomas A.K.L.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(void)
{

    int i, j, k, count, size;
    char frame[30], Nframe[35];
retry:
    printf("Enter the frame only 0s and 1s [max 16 bits]: ");
    scanf("%s", frame);
    i = 0;
    size = 0;
    while (frame[i] != '\0') // frame size counting and frame content validation
    {
        if (frame[i] != '0' && frame[i] != '1')
        {
            printf("\n\nThe imput is restricted to binary digits 0s and 1s, try again !!\n\n");
            goto retry;
        }
        size++;
        i++;
    }
    i = j = 0;
    count = 1;
    while (i < size)
    {
        if (frame[i] == '1')
        {
            Nframe[j] = frame[i];
            for (k = i + 1; frame[k] == '1' && k < size && count < 5; k++)
            {
                j++;                  //select new frame next cell
                Nframe[j] = frame[k]; //one is stored in new frame
                count++;

                if (count == 5)
                {
                    j++;
                    Nframe[j] = '0';
                    count = 0;
                }
                i = k;
            }
        }
        else if (frame[i] == '0')
        {
            Nframe[j] = frame[i];
        }
        i++;
        j++;
    }
    printf("Original frame : %s\n", frame);
    printf("\nNew frame : %s\n", Nframe);
    getchar();
}
