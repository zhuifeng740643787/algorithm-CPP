//
// Created by 宫宜栋 on 2017/6/19.
//

#ifndef ALGORITHM_MERGEBUSORT_H
#define ALGORITHM_MERGEBUSORT_H


#include <iostream>
#include "InsertionSort.h"

using namespace std;

/**
 * 归并排序
 * 自底向上
 * 优点：可对链表进行排序（因为没有使用：通过数组索引去获取元素的操作）
 */
class MergeBUSort {
private:
    static void _merge(int arr[], int left, int mid, int right) {
        if (right <= left) {
            return;
        }

        //复制一份
        int *copyArr = new int[right - left + 1];
        for (int i = left; i <= right; i++) {
            copyArr[i - left] = arr[i];
        }

        //归并过程
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i > mid) {
                arr[k] = copyArr[j - left];
                j++;
            } else if (j > right) {
                arr[k] = copyArr[i - left];
                i++;
            } else {
                if (copyArr[i - left] > copyArr[j - left]) {
                    arr[k] = copyArr[j - left];
                    j++;
                } else {
                    arr[k] = copyArr[i - left];
                    i++;
                }
            }
        }

        delete[]copyArr;


    }

public:
    static void run(int arr[], int n) {

        for (int sz = 1; sz < n; sz = sz << 1) {
            for (int i = 0; i + sz < n; i += 2 * sz) {
                //对arr[i...i+sz-1]与arr[i+sz...i+2*sz-1]进行归并操作，需要保证i+sz<n,即右边数组不为空数组
                if(arr[i+sz-1] > arr[i+sz])
                    _merge(arr, i, i + sz - 1, min(n - 1, i + 2 * sz - 1));
            }
        }

    }
};

#endif //ALGORITHM_MERGEBUSORT_H
