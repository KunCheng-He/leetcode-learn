#include "stdio.h"

// 思路一：找到第一个为零的数，然后往后找到第一个不为零的数，进行位置交换，当找不到不为零的数时结束
void moveZeroes1(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            int j;
            for (j = i+1; j < numsSize; j++)
            {
                if (nums[j] != 0)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
            if (j == numsSize)
                return ;
        }
    }
}

// 思路二：思路一同一个位置可能遍历多次，这里我们使用两个指针从头遍历
//        一个指针往后移动，把非零的数往前移动，到最后以后，两个指针之间的数全部置为0就可以了，每个位置遍历两次
void moveZeroes2(int* nums, int numsSize){
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
            nums[j++] = nums[i];
    }
    while (j < numsSize)
        nums[j++] = 0;
}

int main()
{
    int nums[] = {1,0,0,3,12};
    moveZeroes2(nums, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", nums[i]);
    }
    
    return 0;
}
