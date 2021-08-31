#include "stdio.h"
#include "stdlib.h"

// 思路一：最简单的方式，利用循环嵌套进行查找，这样的时间复杂度为O(n^2)
int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
    // 返回的数组并且这个数组大小为2
    int *returnNums = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int temp;
    for (int i = 0; i < numsSize; i++)
    {
        temp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == temp)
            {
                returnNums[0] = i;
                returnNums[1] = j;
                return returnNums;
            }
        }
    }
    return NULL;
}

// 思路二：采用哈希映射的思想，避免重复查找
int* twoSum2(int* nums, int numsSize, int target, int* returnSize){
    // 返回结果
    *returnSize = 2;
    int *returnNums = (int *)malloc(sizeof(int) * 2);

    // 申明一个哈希记录表
    int hashmap[2][numsSize], hashsize = 1, temp;
    hashmap[0][0] = nums[0];
    hashmap[1][0] = 0;
    for (int i = 1; i < numsSize; i++)
    {
        temp = target - nums[i];
        for (int j = 0; j < hashsize; j++)
        {
            if (hashmap[0][j] == temp)
            {
                returnNums[0] = hashmap[1][j];
                returnNums[1] = i;
                return returnNums;
            }
        }
        hashmap[0][hashsize] = nums[i];
        hashmap[1][hashsize] = i;
        hashsize++;
    }
    return NULL;
}


int main()
{
    int nums[] = {-1,-2,-3,-4,-5}, target = -8, returnSize;
    int *p = twoSum2(nums, 5, target, &returnSize);
    printf("%d---%d\n", p[0], p[1]);
    return 0;
}
