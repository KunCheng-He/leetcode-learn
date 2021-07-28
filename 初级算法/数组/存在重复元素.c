#include "stdio.h"
#include "stdbool.h"

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

// 思路一：先进行排序，然后再检查重复元素
// 这里我使用冒泡排序先举行排序，再检查是否有重复元素
bool containsDuplicate1(int* nums, int numsSize){
    // 冒泡排序
    bubble(nums, numsSize);

    // 检查是否有重复元素
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i+1])
            return true;
    }
    return false;
}

// 思路二：采用哈系映射的方法。这样避免了多次扫描，用一定的空间换取了时间
bool containsDuplicate2(int* nums, int numsSize){
    // 用一个数组来记录映射
    int content[10][numsSize + 1];
    // 初始化一下
    for (int i = 0; i < 10; i++)
        content[i][0] = 0;
    
    int k;
    for (int i = 0; i < numsSize; i++)
    {
        k = nums[i] % 10;
        if (k < 0)
            k = k * (-1);
        
        if (content[k][0] == 0)
        {
            content[k][1] = nums[i];
            content[k][0] = 1;
        }
        else
        {
            for (int j = 1; j <= content[k][0]; j++)
            {
                if (content[k][j] == nums[i])
                    return true;
            }
            content[k][0]++;
            content[k][content[k][0]] = nums[i];
        }
    }
    return false;
}

int main()
{
    int nums[] = {1,5,-2,-4,0};
    /*bubble(nums, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", nums[i]);
    }*/
    printf("%d\n", containsDuplicate2(nums, 5));
    return 0;
}