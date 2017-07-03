//
// Created by 宫宜栋 on 2017/6/16.
//

#ifndef ALGORITHM_SELECTIONSORT_H
#define ALGORITHM_SELECTIONSORT_H

#include <iostream>

using namespace std;

/**
 * 选择排序
 * 从头到尾依次选择最小的元素放到该位置
 */
class SelectionSort {
public:
    static void run(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }


};

#endif //ALGORITHM_SELECTIONSORT_H
