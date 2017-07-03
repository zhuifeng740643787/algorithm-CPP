//
// Created by 宫宜栋 on 2017/6/16.
//

#ifndef ALGORITHM_TESTHELPER_H
#define ALGORITHM_TESTHELPER_H

#include <iostream>

using namespace std;

class TestHelper {

public:

    // 打印数组
    template<typename T>
    static void printArr(T *arr, int n) {
        if (n > 100) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    /**
     * 生成随机数组
     * @param n 数组个数
     * @param min 生成数字的范围 - 最小数
     * @param max 生成数字的范围 - 最大数
     * @return
     */
    static int *generateRandomArr(int n, int min, int max) {
        cout << "无序数组" << endl;
        srand(time(NULL));
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = min + rand() % (max - min);
        }
        return arr;
    }

    /**
     * 复制数组
     * @param arr
     * @param n
     * @return
     */
    static int *copyArr(int arr[], int n) {
        int *newArr = new int[n];
        for (int i = 0; i < n; ++i) {
            newArr[i] = arr[i];
        }
        return newArr;
    }

    /**
     * 生成近乎有序随机数组
     * @param n 数组个数
     * @param swapTimes 无序的个数
     * @return
     */
    static int *generateOrderlyRandomArr(int n, int swapTimes) {
        cout << "近乎有序数组" << endl;
        srand(time(NULL));
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        for (int j = 0; j < swapTimes; ++j) {
            arr[rand() % n] = rand() % n;
        }
        return arr;
    }

    /**
     * 测试排序
     * @param sortName
     * @param sortFunc 排序函数指针
     * @param arr 要排序的数组
     * @param n 要排序数组的个数
     */
    static void testSort(string sortName, void (*sortFunc)(int *, int), int *arr, int n) {
        clock_t startTime = clock();
        sortFunc(arr, n);
        clock_t endTime = clock();
        if (!isOrderly(arr, n)) {
            cout << sortName << ":排序失败" << endl;
            return;
        }
        double duration = double((endTime - startTime)) / CLOCKS_PER_SEC;

        cout << sortName << ": " << duration << "s" << endl;
        return;
    }

    /**
     * 检查数组是否有序
     * @param arr
     * @param n
     * @return
     */
    static bool isOrderly(int *arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }







};

#endif //ALGORITHM_TESTHELPER_H
