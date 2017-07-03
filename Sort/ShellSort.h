//
// Created by 宫宜栋 on 2017/6/16.
//

#ifndef ALGORITHM_SHELLSORT_H
#define ALGORITHM_SHELLSORT_H

#include <iostream>

using namespace std;

/**
 * 希尔排序 O(n2)
 * 基于插入排序，将数组先分成以d=n/2为间隔的组,依次对这d组进行一次插入排序，完成后，再将数组分成d=d/2份，。。。直到d=1
 * 优点：通过设置间隔d,可以让一个元素一次性的朝最终位置前进一大步（插入排序一次只能移动一步）
 */
class ShellSort {

public:
    static void run(int arr[], int n) {
        int d;//元素间的间隔
        for (d = n / 2; d >= 1; d /= 2) {
            for (int i = 0; i < d; i++) {
                for (int j = i + d; j < n; j += d) {
                    //插入排序
                    int e = arr[j];
                    int k;
                    for (k = j; k > i && arr[k - 1] > e; k -= d) {
                        arr[k] = arr[k - d];
                    }
                    arr[k] = e;
                }
            }
        }
    }

};

#endif //ALGORITHM_SHELLSORT_H
