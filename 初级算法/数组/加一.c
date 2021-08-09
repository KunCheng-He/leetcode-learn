#include "stdio.h"
#include "stdlib.h"

// 思路一：找到原先的数字，再进行加一的操作，最后将各个数位的数字分格开来
//        这种思路最终没有提交成功，因为int型的大小限制，所以当输入很长时，会报错
int* plusOne1(int* digits, int digitsSize, int* returnSize){
    // sum用来记录输入的这个数组组成的数字是多少
    long int sum = 0;
    for (int i = 0; i < digitsSize; i++)
        sum = sum * 10 + digits[i];
    sum++;
    
    // 返回的数组
    int *array = (int *)malloc((digitsSize + 1)*sizeof(int));
    *returnSize = 0;

    // 将求出的和每一位分隔开来存储，将每一位分隔出来后得到的数组是倒序的
    int num;
    while (sum > 0)
    {
        num = sum%10;
        array[*returnSize] = num;
        (*returnSize)++;
        sum /= 10;
    }

    // 将数组的顺序调换回来
    int i = 0, j = (*returnSize) - 1, temp;
    while (i<j)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return array;
}

// 思路二：因为只有遇到9才可能出现数位加一的情况，所以我们从后往前加，遇见进位就继续加
//        如果位数没有加一，我们返回array[1]的地址，如果加一了，我们返回array就可以了
int* plusOne2(int* digits, int digitsSize, int* returnSize){
    // 多申请一个数位，防止加一让数位变多
    int *array = (int *)malloc((digitsSize + 1)*sizeof(int));
    *returnSize = digitsSize;

    // flag用来标记数位是否加一了
    int flag = 0, sum, num = 1;
    while (digitsSize>0)
    {
        sum = digits[digitsSize - 1] + num;
        if (sum == 10)
        {
            array[digitsSize] = 0;
            flag = 1;
        }
        else
        {
            array[digitsSize] = sum;
            num = 0;
            flag = 0;
        }
        digitsSize--;
    }
    if (flag == 1)
    {
        array[0] = 1;
        (*returnSize)++;
        return array;
    }
    else
        return array + 1;
}

int main()
{
    int digits[] = {9};
    int returnSize, *array;
    array = plusOne2(digits, 1, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\n", array[i]);
    }
    
    
    return 0;
}
