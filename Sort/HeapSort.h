//
// Created by 宫宜栋 on 2017/6/20.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include <iostream>
#include "../Heap/MaxHeap.h"

class HeapSort {
private:
    static void _shiftDown(int arr[], int n, int i) {
        assert(i >= 0);
        while (2 * i + 1 < n) {
            int k = 2 * i + 1;
            if(k + 1 < n && arr[k + 1] > arr[k]) {
                k++;
            }
            if(arr[i] >= arr[k]) {
                break;
            }
            swap(arr[i], arr[k]);
            i = k;
        }
    }

public:
    //入堆，出堆
    static void run(int arr[], int n) {
        MaxHeap *maxHeap = new MaxHeap(n);
        for (int i = 0; i < n; ++i) {
            maxHeap->insert(arr[i]);
        }

        for (int j = n - 1; j >= 0; --j) {
            arr[j] = maxHeap->extract();
        }
    }

    //heapify
    static void runOptimize(int arr[], int n) {
        MaxHeap *maxHeap = new MaxHeap(arr, n);
        for (int j = n - 1; j >= 0; --j) {
            arr[j] = maxHeap->extract();
        }
    }

    //原地堆排序
    static void runOptimize2(int arr[], int n) {
        //先将数组转为堆结构
        for (int i = (n - 2) / 2; i >= 0; --i) {
            _shiftDown(arr, n, i);
        }
        //头尾元素交换（即最大值放在了尾部）,对首元素进行shiftDown操作
        for (int j = n-1; j >= 1; --j) {
           swap(arr[0], arr[j]);
            _shiftDown(arr, j, 0);
        }
    }

};

#endif //ALGORITHM_HEAPSORT_H
