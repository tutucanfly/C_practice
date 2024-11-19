#include <stdio.h>
#include <malloc.h>

int* twoSum(int* price, int priceSize, int target, int* returnSize) {
    int i = 0, j = 1;
    // 遍历数组寻找满足条件的两个数
    while (i < priceSize - 1) {
        if (price[i] + price[j] == target) {
            // 找到目标值，分配内存并返回结果
            int* result = (int*)malloc(2 * sizeof(int)); // 动态分配内存
            result[0] = price[i]; // 返回索引而非值
            result[1] = price[j];
            *returnSize = 2; // 设置返回数组的大小
            return result;
        }
        j++;
        if (j >= priceSize) { // 如果 j 超出范围，移动 i，并重置 j
            i++;
            j = i + 1;
        }
    }

    // 如果没有找到目标值，返回 NULL
    *returnSize = 0;
    return NULL;
}