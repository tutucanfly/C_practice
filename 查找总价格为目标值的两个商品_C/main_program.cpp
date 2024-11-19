#include <stdio.h>
#include <malloc.h>

int* twoSum(int* price, int priceSize, int target, int* returnSize) {
    int i = 0, j = 1;
    // ��������Ѱ������������������
    while (i < priceSize - 1) {
        if (price[i] + price[j] == target) {
            // �ҵ�Ŀ��ֵ�������ڴ沢���ؽ��
            int* result = (int*)malloc(2 * sizeof(int)); // ��̬�����ڴ�
            result[0] = price[i]; // ������������ֵ
            result[1] = price[j];
            *returnSize = 2; // ���÷�������Ĵ�С
            return result;
        }
        j++;
        if (j >= priceSize) { // ��� j ������Χ���ƶ� i�������� j
            i++;
            j = i + 1;
        }
    }

    // ���û���ҵ�Ŀ��ֵ������ NULL
    *returnSize = 0;
    return NULL;
}