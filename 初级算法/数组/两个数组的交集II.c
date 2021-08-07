#include "stdio.h"
#include "stdlib.h"

// 思路一：两个指针，依次比较，找到相同的元素后将最后的元素前移，再进行下一轮比较
int* intersect1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int small;
    if (nums1Size>nums2Size)
        small = nums2Size;
    else
        small = nums1Size;

    int *array = (int *)malloc(small*sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < nums1Size && *returnSize <= small; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                array[*returnSize] = nums1[i];
                (*returnSize)++;
                nums2Size--;
                nums2[j] = nums2[nums2Size];
                break;
            }
        }
    }

    return array;
}

// 思路二：将短的那一个数组通过哈希映射，并记录次数
//        之后遍历一遍长的那一个数组，对照哈希表，将重复元素输出，输出一次次数减一，为零后就算重复也不再输出

// 思路三：排序，先对两个数组进行排序，然后用双指针
//        相等都往后移，不等，小的往后移，继续比较

// 快速排序
int Partition(int *nums, int small, int big)
{    
    int p = nums[small];
    while (small < big)
    {
        while(small<big && nums[big] >= p) big--;
        nums[small] = nums[big];
        while (small<big && nums[small] <= p) small++;
        nums[big] = nums[small];        
    }
    nums[small] = p;
    return small;
}

void QuickSort(int *nums, int small, int big)
{
    if (small < big)
    {
        int p = Partition(nums, small, big);
        QuickSort(nums, small, p-1);
        QuickSort(nums, p+1, big);
    }
    
}

int* intersect2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    QuickSort(nums1, 0, nums1Size - 1);
    QuickSort(nums2, 0, nums2Size - 1);

    int small = (nums1Size>nums2Size ? nums2Size : nums1Size);
    int *array = (int *)malloc(small*sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if(nums1[i] == nums2[j])
        {
            array[*returnSize] = nums1[i];
            (*returnSize)++;
            i++;
            j++;
        }
        else
        {
            if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
    }
    return array;
}



int main()
{
    int nums1[] = {1,2,2,1}, nums2[] = {2,2};
    int *array, returnSize;
    array = intersect2(nums1, 4, nums2, 2, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\n", array[i]);
    }

    // int nums[] = {8,4,6,3,5,8,1,5,8,5};
    // QuickSort(nums, 0, 9);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d\n", nums[i]);
    // }
    
    
    return 0;
}
