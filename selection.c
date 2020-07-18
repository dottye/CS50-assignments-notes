#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/*
    Testing selection sorting: grab the smallest item and swap it with the first place value
    O (n^2)
    Ω (n^2)
    Pseudocode:
    For i from 0 to n–1
        Find smallest item between i'th item and last item
        Swap smallest item with i'th item
*/

// Function prototypes
void selsort(int nums[], int len);

int main(void)
{
    int len = 8;
    int nums[8] = {5, 1, 7, 4, 4, 9, 11, 4};
    selsort(nums, len);
}

void selsort(int nums[], int len)
{
    int temp = 0;
    int small = 0;
    for (int i = 0; i < len - 1; i++)
    {
        small = nums[i];
        for (int j = i; j < len; j++)
        {
            if (small > nums[j + 1])
            {
                nums[i] = nums[j + 1];
                nums[j + 1] = small;
                small = nums[i];
                // printf("i, j:  %i, %i\n", i, j);
                // printf("nums[i]: %i\n", nums[i]);
                // printf("nums[j + 1]: %i\n", nums[j + 1]);
            }
        }

    //printf("%i ", nums[i]);
    }

    for (int k = 0; k < len; k++)
    {
        printf("%i ", nums[k]);
    }
    printf("\n");
}
