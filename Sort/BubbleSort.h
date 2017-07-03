//
// Created by 宫宜栋 on 2017/6/19.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H


#include <iostream>

using namespace std;

/**
 * 冒泡排序
 * 从头依次遍历数组，比较相邻两元素的值，大的元素向后移动
 */
class BubbleSort {

public:
    static void run(int arr[], int n) {

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if(arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }


};

#endif //ALGORITHM_BUBBLESORT_H
