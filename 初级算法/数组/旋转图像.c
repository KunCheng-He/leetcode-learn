#include "stdio.h"


// 思路一：两次遍历，第一次遍历用一个新的矩阵来存储结果，第二次遍历将结果拷贝回原矩阵
void rotate1(int** matrix, int matrixSize, int* matrixColSize){
    // 存储结果的临时矩阵
    int tempMatrix[matrixSize][*matrixColSize];

    // 第一轮存储结果
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
            tempMatrix[j][i] = matrix[i][j];
    }
    
    // 第二轮拷贝结果
    int col = (*matrixColSize) - 1;
    for (int i = 0; i < *matrixColSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
            matrix[j][i] = tempMatrix[j][col];
        col--;
    }
}


// 思路二：原地旋转，分析看同文件夹下 "旋转图像-旋转分析.png"
void rotate2(int** matrix, int matrixSize, int* matrixColSize){
    int temp;
    for (int row = 0, col = matrixSize - 1; row < matrixSize / 2; row++, col--)
    {
        for (int addIndex = row, subIndex = col; addIndex < col; addIndex++, subIndex--)
        {
            temp = matrix[row][addIndex];
            matrix[row][addIndex] = matrix[subIndex][row];
            matrix[subIndex][row] = matrix[col][subIndex];
            matrix[col][subIndex] = matrix[addIndex][col];
            matrix[addIndex][col] = temp;
        }
    }
}


// 思路三：翻转的过程可以转换为交换过程，先行进行倒序，再按对角线交换
void rotate3(int** matrix, int matrixSize, int* matrixColSize){
    int temp;

    // 行交换
    for (int rowStart = 0, rowEnd = matrixSize - 1; rowStart < rowEnd; rowStart++, rowEnd--)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            temp = matrix[rowStart][col];
            matrix[rowStart][col] = matrix[rowEnd][col];
            matrix[rowEnd][col] = temp;
        }
    }

    // 对角线交换
    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = row + 1; col < matrixSize; col++)
        {
            temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
}

int main()
{
    int col = 2;
    int nums[3][3] = {1,2,3,4,5,6,7,8,9};
    int *p[3];
    p[0] = &nums[0][0];
    p[1] = &nums[1][0];
    p[2] = &nums[2][0];
    int **matrix = p;

    rotate3(matrix, 3, &col);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ---", nums[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
