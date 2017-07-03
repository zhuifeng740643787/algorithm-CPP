//
// Created by 宫宜栋 on 2017/6/16.
//

#ifndef ALGORITHM_INSERTIONSORT_H
#define ALGORITHM_INSERTIONSORT_H

#include <iostream>

using namespace std;

/**
 * 选择排序
 * 从第二个元素开始依次往前插入到该放的位置
 * 优点：可以提前结束遍历；最适合近乎有序的数组
 */
class InsertionSort {
public:
    //对arr[left...right]区间进行归并排序
    static void api(int arr[], int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int e = arr[i];
            int j;
            for (j = i; j > left && arr[j - 1] > e; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    static void run(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            //swap操作耗时，需优化
            for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    //优化swap操作
    static void runOptimize(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            int e = arr[i];//复制一份i位置元素的值
            int j;//保留e元素应该放的位置
            //依次判断i前面的值是否大于e
            for (j = i; j > 0 && arr[j - 1] > e; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

};

#endif //ALGORITHM_INSERTIONSORT_H
