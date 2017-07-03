#include <iostream>
#include <vector>
#include <math.h>

#include "Sort/SelectionSort.h"
#include "Sort/BubbleSort.h"
#include "Sort/InsertionSort.h"
#include "Sort/ShellSort.h"
#include "Sort/MergeSort.h"
#include "Sort/MergeBUSort.h"
#include "Sort/QuickSortSingleWay.h"
#include "Sort/QuickSortTwoWays.h"
#include "Sort/QuickSortThreeWays.h"
#include "Sort/HeapSort.h"

#include "Helper/TestHelper.h"

using namespace std;

void test(int min, int max, bool isOrderly) {
    for (int i = min; i <= max; i *= 10) {
        int n = i;
        cout<<"排序个数="<<n<<endl;
        int *arr;
        arr = !isOrderly ? TestHelper::generateRandomArr(n, 0, n) : TestHelper::generateOrderlyRandomArr(n, 10);
        int *arr1 = TestHelper::copyArr(arr, n);
        int *arr2 = TestHelper::copyArr(arr, n);
        int *arr3 = TestHelper::copyArr(arr, n);
        int *arr4 = TestHelper::copyArr(arr, n);
        int *arr5 = TestHelper::copyArr(arr, n);
        int *arr6 = TestHelper::copyArr(arr, n);
        int *arr7 = TestHelper::copyArr(arr, n);
        int *arr8 = TestHelper::copyArr(arr, n);
        int *arr9 = TestHelper::copyArr(arr, n);
        int *arr10 = TestHelper::copyArr(arr, n);
        int *arr11 = TestHelper::copyArr(arr, n);
        int *arr12 = TestHelper::copyArr(arr, n);
        int *arr13 = TestHelper::copyArr(arr, n);
        TestHelper::printArr(arr, n);
//        TestHelper::testSort("选择排序", SelectionSort::run, arr, n);
//        TestHelper::printArr(arr, n);
//        TestHelper::testSort("冒泡排序", BubbleSort::run, arr1, n);
//        TestHelper::printArr(arr1, n);
//        TestHelper::testSort("插入排序", InsertionSort::run, arr2, n);
//        TestHelper::printArr(arr2, n);
//        TestHelper::testSort("插入排序优化", InsertionSort::runOptimize, arr3, n);
//        TestHelper::printArr(arr3, n);
//        TestHelper::testSort("希尔排序", ShellSort::run, arr4, n);
//        TestHelper::printArr(arr4, n);
//        TestHelper::testSort("归并排序", MergeSort::run, arr5, n);
//        TestHelper::printArr(arr5, n);
        TestHelper::testSort("归并排序优化", MergeSort::runOptimize, arr6, n);
        TestHelper::printArr(arr6, n);
        TestHelper::testSort("归并排序自底向上", MergeBUSort::run, arr7, n);
        TestHelper::printArr(arr7, n);
//        TestHelper::testSort("快速排序-单路", QuickSortSingleWay::run, arr8, n);
//        TestHelper::printArr(arr8, n);
        TestHelper::testSort("快速排序-双路", QuickSortTwoWays::run, arr9, n);
        TestHelper::printArr(arr9, n);
        TestHelper::testSort("快速排序-三路", QuickSortThreeWays::run, arr10, n);
        TestHelper::printArr(arr10, n);
        TestHelper::testSort("堆排序", HeapSort::run, arr11, n);
        TestHelper::printArr(arr11, n);
        TestHelper::testSort("堆排序优化1", HeapSort::runOptimize, arr12, n);
        TestHelper::printArr(arr12, n);
        TestHelper::testSort("原地堆排序", HeapSort::runOptimize2, arr13, n);
        TestHelper::printArr(arr13, n);
        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
        delete[] arr6;
        delete[] arr7;
        delete[] arr8;
        delete[] arr9;
        delete[] arr10;
        delete[] arr11;
        delete[] arr12;
        delete[] arr13;
    }
    cout<<endl<<"------------------------------"<<endl;
}

int main() {

    int n = 1000000;
//    test(n, n, true);
    test(n, n, false);
    return 0;
}
