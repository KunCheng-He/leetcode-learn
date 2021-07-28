#include "stdio.h"

int removeDuplicates(int* nums, int numsSize){
    int i = 0, j = 1;
    // 我们应该考虑数组为空的情况
    if (numsSize == 0)
        return 0;
    while (j < numsSize)
    {
        if (nums[j] != nums[i])
            nums[++i] = nums[j];
        j++;
    }
    return i+1;
}

int main()
{
    int nums[] = {0, 0, 0, 0, 2, 2, 2, 3, 3};
    int i = removeDuplicates(nums, 9);
    for (int j = 0; j<i-1; j++)
    {
        printf("%d ", nums[j]);
    }
    printf("%d\n", nums[i-1]);
    return 0;
}
