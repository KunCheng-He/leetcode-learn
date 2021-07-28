#include "stdio.h"
#include "stdlib.h"

// 打印数组的方法
void view(int *nums)
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// 第一种思路：每次移动一位，循环移动k次
// 时间复杂度O(kn)，空间复杂度O(1)
void rotate1(int* nums, int numsSize, int k){
    if (numsSize < 2)
        return ;
    
    while (k--)
    {
        int temp = nums[numsSize - 1];
        for (int i = numsSize - 1; i > 0; i--)
            nums[i] = nums[i - 1];
        nums[0] = temp;
    }
}

// 第二种思路：计算取模，用空间换时间
// 时间复杂度O(n)，空间复杂度O(n)
void rotate2(int* nums, int numsSize, int k){
    int new[numsSize];
    for (int i = 0; i < numsSize; i++)
        new[(i + k) % numsSize] = nums[i];
    for (int i = 0; i < numsSize; i++)
        nums[i] = new[i];
}

// 第三种思路：环状替换，基于第二种思路做的，第二种的思路中我们使用的了一个新的数组，最后进行复制
// 所以，我们也可以用一个临时变量来解决空间的消耗问题
void rotate3(int* nums, int numsSize, int k){
    int count = 0;  // 用于记录替换了多少次
    int old, new, flag, j;
    for (int i = 0; i < numsSize; i++)
    {
        flag = i;
        old = nums[flag];
        do
        {
            j = (flag + k) % numsSize;
            new = nums[j];
            nums[j] = old;
            old = new;
            flag = j;
            count++;
        } while (flag != i && count <= numsSize);
        if (count >= numsSize)
        {
            break;
        }
    }
}

// 反转的方法   将数组下标从i到j的值进行反转
void reserve(int *nums, int i, int j)
{
    int temp;
    while (i< j)
    {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

// 第四种思路：数组反转
void rotate4(int* nums, int numsSize, int k){
    reserve(nums, 0, numsSize - 1);
    if (k > numsSize)
        k = k % numsSize;
    reserve(nums, 0, k - 1);
    reserve(nums, k, numsSize - 1);
}

int main()
{
    int nums[] = {1,2,3,4,5,6,7};
    rotate4(nums, 7, 3);
    view(nums);
    return 0;
}
