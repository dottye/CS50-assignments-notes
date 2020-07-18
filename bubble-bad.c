#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

/*
    Bubble Sort: larger values 'bubble' to the top
    Without the 'until no steps' checker: many more steps
*/


int main(void)
{
    int len = 8;
    int nums[8] = {5, 1, 7, 2, 4, 9, 11, 6};
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            printf("j: %i\n", j);
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                printf("nums[j + 1]: %i\n", nums[j + 1]);  // visualization of when swaps occur during runtime
                printf("nums[j]: %i\n", nums[j]);
            }
        }
    }

    for (int a = 0; a < len; a++)
    {
        printf("%i ", nums[a]);
    }
    printf("\n");
}

/*
j: 0
nums[j + 1: 5
nums[j: 1
j: 1
j: 2
nums[j + 1: 7
nums[j: 2
j: 3
nums[j + 1: 7
nums[j: 4
j: 4
j: 5
j: 6
nums[j + 1: 11
nums[j: 6
j: 0
j: 1
nums[j + 1: 5
nums[j: 2
j: 2
nums[j + 1: 5
nums[j: 4
j: 3
j: 4
j: 5
nums[j + 1: 9
nums[j: 6
j: 6
j: 0
j: 1
j: 2
j: 3
j: 4
nums[j + 1: 7
nums[j: 6
j: 5
j: 6
j: 0
j: 1
j: 2
j: 3
j: 4
j: 5
j: 6
j: 0
j: 1
j: 2
j: 3
j: 4
j: 5
j: 6
j: 0
j: 1
j: 2
j: 3
j: 4
j: 5
j: 6
j: 0
j: 1
j: 2
j: 3
j: 4
j: 5
j: 6
j: 6
1 2 4 5 6 7 9 11
*/
