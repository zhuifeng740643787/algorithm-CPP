//
// Created by 宫宜栋 on 2017/6/20.
//

#ifndef ALGORITHM_QUICKSORTTHREEWAYS_H
#define ALGORITHM_QUICKSORTTHREEWAYS_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;

/**
 * 三路快速排序
 * 以首元素arr[left]=v为比较对象，将数组分为三个区间arr[left+1...lt]<v, arr[lt+1...i-1]=v, arr[gt...right]>v
 * 交换arr[left]与arr[lt-1]的值，lt--， 然后分别对[left...lt]和[gt...right]两区间进行快排
 */
class QuickSortThreeWays {
private:
    static void _quickSortThreeWays(int arr[], int left, int right) {
        if (right <= left + 31) {
            InsertionSort::api(arr, left, right);
            return;
        }
        //交换首元素与之后任意元素的值
        swap(arr[left], arr[left + rand() % (right - left + 1)]);

        //定义区间及索引 arr[left+1...lt] < v, arr[lt+1...i-1] = v, arr[gt...right] > v
        int v = arr[left],
            i, lt = left, gt = right + 1;

        // 分组过程
        for (i = left + 1; i < gt; i++) {
            if(arr[i] == v) {
                continue;
            }

            if (arr[i] < v) {
                swap(arr[i], arr[++lt]);
            } else {
                swap(arr[i--], arr[--gt]);
            }
        }
        //交换left与lt-1位置的值，lt--
        swap(arr[left], arr[lt--]);

        //分别对[left...lt] 和 [gt...right]进行快排
        _quickSortThreeWays(arr, left, lt);
        _quickSortThreeWays(arr, gt, right);
    }

public:
    static void run(int arr[], int n) {
        srand(time(NULL));
        _quickSortThreeWays(arr, 0, n - 1);

    }
};

#endif //ALGORITHM_QUICKSORTTHREEWAYS_H
