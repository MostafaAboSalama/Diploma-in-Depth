#include <stdio.h>

#define GET_BIT(X, BIT) ((X)&(1<<(BIT)))

int CountMaxOnes( int x);
int main(void)
{
    printf("ans = %d\n", CountMaxOnes(62));
    return 0;
}

int CountMaxOnes( int x)
{
    int arr[32] = {0}; // store positions of zeros
    int j = 0;
    for(int i=0; i<32; i++)
    {
        if(GET_BIT(x, i) == 0)
            arr[j++] = i+1; // avoid conflicting between index 0 and inintialized index with 0 (return max -1)
    }
    int max = 0;
    for(int i=0; i<32; i++)
    {
        if(arr[i] == 0)
            break;
        if(max < arr[i+1] - arr[i])
            max = arr[i+1] - arr[i];
    }

    return max-1;
}