#include "stdio.h"

// 考虑较多情况
int max1Profit(int* prices, int pricesSize){
    // 小于两天，都不可能赚钱
    if (pricesSize < 2)
        return 0;
    
    int sum = 0, flag = 0, tag;
    for (int i = 1; i < pricesSize; i++)
    {
        // 找低点
        if (flag==0 && prices[i] > prices[i-1])
        {
            tag = i - 1;
            flag = 1;
            // 已经是结尾两天升的情况
            if (i == pricesSize - 1)
                sum = sum + (prices[i] - prices[tag]);
        }
        // 找高点
        else if(flag==1)
        {
            if (prices[i] < prices[i-1])
            {
                sum = sum + (prices[i-1] - prices[tag]);
                flag = 0;
            }
            // 高点结束
            else if (i == pricesSize - 1)
            {
                sum = sum + (prices[i] - prices[tag]);
                flag = 0;
            }
        }
    }
    return sum;
}

// 官方解答
/* 因为交易我们不算手续费，所以我们将相邻两天的价格比较，高抛低吸 */
int maxProfit(int* prices, int pricesSize){
    // 小于两天，都不可能赚钱
    if (pricesSize < 2)
        return 0;

    int max = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i-1])
            max += (prices[i] - prices[i-1]);
    }
    return max;
}

int main()
{
    int prices[] = {2, 1, 4};
    printf("%d\n", maxProfit(prices, 3));
    return 0;
}
