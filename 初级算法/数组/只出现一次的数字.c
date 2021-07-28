#include "stdio.h"

// 冒泡排序
void bubble(int* nums, int numsSize)
{
    // flag标记循环是否进行过交换 n用来记录冒泡的次数  temp用来临时交换值
    int flag = 1, n = 0, temp;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < numsSize - 1 - n; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                temp = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = temp;
                flag = 1;
            }
        }
        n++;
    }
}

// 思路一：先进行排序，排序以后再遍历一遍，就知道只出现一次的数字是谁了
// 时间开销主要在排序和遍历上，也需要常数级的空间开销
int singleNumber1(int* nums, int numsSize){
    // 先排序
    bubble(nums, numsSize);

    // 再遍历查找
    for (int i = 0; i < numsSize - 1; i+=2)
    {
        if (nums[i] != nums[i + 1])
            return nums[i];
    }
    return nums[numsSize - 1];
}

// 思路二：异或可以去除偶数个重复元素，
int singleNumber2(int nums[], int numsSize){
    for (int i = 1; i < numsSize; i++)
        nums[0] ^=nums[i];
    return nums[0];
}

int main()
{
    int nums[] = {2,2,1};
    printf("%d\n", singleNumber2(nums, 3));
    
    return 0;
}
