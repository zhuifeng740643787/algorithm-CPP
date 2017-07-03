//
// Created by 宫宜栋 on 2017/6/19.
//

#ifndef ALGORITHM_QUICKSORTSINGLEWAY_H
#define ALGORITHM_QUICKSORTSINGLEWAY_H


#include <iostream>
#include "InsertionSort.h"

using namespace std;

/**
 * 快速排序
 * 1.交换第一个元素与之后任意元素
 * 2.将数组分割为arr[left...p-1], arr[p+1...right],找到分割点p
 * 3.对两组数组分别进行快排序
 * 缺点：含有大量重复元素时,有可能退化为O(n2),因为大量重复数据会把数组分割为两个极度不均衡的数组
 */
class QuickSortSingleWay {
private:

    //找到区间分割的位置
    static int _partition(int arr[], int left, int right) {
        //对第一个元素与之后的任意一元素进行交换，防止数组近乎有序时退化为O(n2)
        swap(arr[left], arr[left + rand() % (right - left + 1)]);
        //定义区间含义 arr[left+1...j] <= v, arr[j+1...i-1] > v
        int v = arr[left];
        int i, j = left;
        //遍历数组
        for (i = left + 1; i <= right; i++) {
            if(arr[i] >= v) {
                continue;
            }
            //交换arr[i] 与 arr[j+1]的值，j++
            swap(arr[i], arr[j+1]);
            j++;
        }
        //交换arr[left]与arr[j]的值
        swap(arr[left], arr[j]);

        return j;
    }

    //对arr[left...right]区间的元素进行快速排序
    static void _quickSort(int arr[], int left, int right) {
        if (right <= left + 31) {
            InsertionSort::api(arr, left, right);
            return;
        }

        //以第一个元素为基准，将区间分为两部分，arr[left...p-1] <= arr[left], arr[p+1...right] > v,找到p索引位置
        int p = _partition(arr, left, right);
        //分别对arr[left...p-1]和arr[p+1...right]两区间进行快速排序
        _quickSort(arr, left, p - 1);
        _quickSort(arr, p + 1, right);


    }

public:
    static void run(int arr[], int n) {
        srand(time(NULL));
        _quickSort(arr, 0, n - 1);
    }
};

#endif //ALGORITHM_QUICKSORTSINGLEWAY_H
