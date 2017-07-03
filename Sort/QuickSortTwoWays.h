//
// Created by 宫宜栋 on 2017/6/19.
//

#ifndef ALGORITHM_QUICKSORTTWOWAYS_H
#define ALGORITHM_QUICKSORTTWOWAYS_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;

/**
 * 双路快速排序
 * 使用两个索引i,j分别对数组前后进行遍历
 * 以首元素arr[left]=v为比较对象, 将数组分为两个区间arr[left+1...i-1]<=v, arr[j+1...right]>=v
 * 最终交换left与j的位置，再分别对[left...j-1]和[j+1...right]进行快排
 */
class QuickSortTwoWays {
private:
    static int _partition(int arr[], int left, int right) {
        swap(arr[left], arr[left + (rand() % (right - left + 1))]);
        //定义区间 arr[left+1...i-1]<=v, arr[j+1...right]>=v
        int v = arr[left];
        int i = left + 1, j = right;
        while (true) {
            //向后移动i索引，直到arr[i] > v
            while (arr[i] <= v && i <= right) {
                i++;
            }
            //向前移动j索引，直到arr[j] < v
            while (arr[j] >= v && j >= left + 1) {
                j--;
            }


            //如果j索引移动到了i的前面，说明已遍历完成，则退出循环
            if(i > j) {
                break;
            }
            //到这一步说明arr[i] > v 且 arr[j] < v,则交换两者的值，且i++,j--
            swap(arr[i++], arr[j--]);
        }

        //交换left与第一个>=v的j位置的元素，并返回j
        swap(arr[left], arr[j]);
        return j;
    }

    static void _quickSortTwoWays(int arr[], int left, int right) {
        if (right <= left + 31) {
            InsertionSort::api(arr, left, right);
            return;
        }

        int p = _partition(arr, left, right);
        _quickSortTwoWays(arr, left, p - 1);
        _quickSortTwoWays(arr, p + 1, right);
    }

public:
    static void run(int arr[], int n) {
        srand(time(NULL));
        _quickSortTwoWays(arr, 0, n - 1);
    }
};

#endif //ALGORITHM_QUICKSORTTWOWAYS_H
