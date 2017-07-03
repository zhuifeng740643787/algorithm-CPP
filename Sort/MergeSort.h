//
// Created by 宫宜栋 on 2017/6/19.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H


#include <iostream>
#include <cassert>
#include "InsertionSort.h"

using namespace std;

/**
 * 归并排序 O(nlogn)
 * 分治算法 自顶向下
 * 将数组从中间分割为左右两半，然后对左右两边数组再进行分割。。。只到子数组元素个数为1，然后对子数组逐层进行归并
 * 使用递归
 */

class MergeSort {
private:
    //对arr[left...right]区间进行归并排序
    static void _mergeSort(int arr[], int left, int right) {
        //待优化1
        if (right <= left) {
            return;
        }
        int mid = left + (right - left) / 2;//选取中间位置
        _mergeSort(arr, left, mid);//归并排序左边子数组
        _mergeSort(arr, mid + 1, right);//归并排序右边子数组
        //待优化2
        _merge(arr, left, mid, right);//合并两个子数组
    }

    //对arr[left...right]区间进行归并排序
    static void _mergeSortOptimize(int arr[], int left, int right) {
        //待优化
        if (right <= left + 15) {
            InsertionSort::api(arr, left, right);
            return;
        }
        int mid = left + (right - left) / 2;//选取中间位置
        _mergeSort(arr, left, mid);//归并排序左边子数组
        _mergeSort(arr, mid + 1, right);//归并排序右边子数组
        if (arr[mid] > arr[mid + 1]) {
            _merge(arr, left, mid, right);//合并两个子数组
        }
    }


    //合并两个子数组[left, mid] 与 [mid+1, right]
    static void _merge(int arr[], int left, int mid, int right) {

        //复制一份数组
        int *copyArr = new int[right - left + 1];
        for (int i = 0; i <= right - left; i++) {
            copyArr[i] = arr[i + left];
        }

        //定义两个索引i,j，分别处于以mid分割两边copyArr数组的开头位置
        int i = 0, j = mid - left + 1;
        //遍历[left, right]区间，依次赋值
        for (int k = left; k <= right; k++) {
            if (i > mid - left) {
                arr[k] = copyArr[j++];
            } else if (j > right - left) {
                arr[k] = copyArr[i++];
            } else {
                //比较i位置的元素值与j位置的元素值
                if (copyArr[i] <= copyArr[j]) {
                    arr[k] = copyArr[i++];
                } else {
                    arr[k] = copyArr[j++];
                }
            }
        }
        delete[] copyArr;
    }

public:
    static void run(int arr[], int n) {
        _mergeSort(arr, 0, n-1);
    }

    static void runOptimize(int arr[], int n) {
        _mergeSortOptimize(arr, 0, n-1);
    }
};


#endif //ALGORITHM_MERGESORT_H
