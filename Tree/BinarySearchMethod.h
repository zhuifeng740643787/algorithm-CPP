//
// Created by 宫宜栋 on 2017/6/21.
//

#ifndef ALGORITHM_BINARYSEARCHMETHOD_H
#define ALGORITHM_BINARYSEARCHMETHOD_H

#include <iostream>

using namespace std;

/**
 * 二分查找法
 * 前提：数组有序
 */
class BinarySearchMethod {
private:
    /**
     * 二分查找 [left...right]区间内查找
     * @param arr
     * @param left
     * @param right
     * @param k
     * @return
     */
    static int _binarySearch(int arr[], int left, int right, int k) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (k == arr[mid]) {
            return mid;
        }

        if (k < arr[mid]) {
            return _binarySearch(arr, left, mid - 1, k);
        }

        return _binarySearch(arr, mid + 1, right, k);

    }

public:
    static int run(int arr[], int n, int k) {
        return _binarySearch(arr, 0, n - 1, k);
    }
};


#endif //ALGORITHM_BINARYSEARCHMETHOD_H
