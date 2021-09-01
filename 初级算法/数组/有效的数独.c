#include "stdio.h"
#include "stdbool.h"

// 思路一：这里有三个检测规则，我们建立三张表的存储信息 char** board, int boardSize, int* boardColSize
bool isValidSudoku1(){
    char board[9][9] = {
        {'.','.','4','.','.','.','6','3','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','9','.'},
        {'.','.','.','5','6','.','.','.','.'},
        {'4','.','3','.','.','.','.','.','1'},
        {'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','5','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };

    // 三张表
    int rowTable[10][10];  // 行记录表
    int columnsTable[10][10];  // 列记录表
    int blockTable[10][10];  // 九宫格记录

    // 初始化三张表
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rowTable[i][j] = 0;
            columnsTable[i][j] = 0;
            blockTable[i][j] = 0;
        }
    }
    
    // 遍历数独表
    int num;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            switch (board[i][j])
            {
                case '1': num = 1; break;
                case '2': num = 2; break;
                case '3': num = 3; break;
                case '4': num = 4; break;
                case '5': num = 5; break;
                case '6': num = 6; break;
                case '7': num = 7; break;
                case '8': num = 8; break;
                case '9': num = 9; break;
                default:
                    break;
            }          
            
            // 行表记录
            if (rowTable[i][num])
                return false;
            rowTable[i][num] = 1;

            // 列表记录
            if (columnsTable[j][num])
                return false;
            columnsTable[j][num] = 1;

            // 九宫格表记录
            int index = (i / 3) * 3 + (j / 3);  // 将行列下标映射到九宫格下标
            if (blockTable[index][num])
                return false;
            blockTable[index][num] = 1;
        }
    }
    return true;
}

int main()
{
    printf("%d\n", isValidSudoku1());
    return 0;
}
