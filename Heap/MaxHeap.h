//
// Created by 宫宜栋 on 2017/6/20.
//

#ifndef ALGORITHM_MAXHEAP_H
#define ALGORITHM_MAXHEAP_H

#include <iostream>
#include <cassert>

using namespace std;

/**
 * 最大堆
 */
class MaxHeap {

private:
    int *data;
    int capacity;
    int count;

    //向二叉树的根节点方向移动元素
    void _shiftUp(int i) {
        //有父节点，且父节点的值小于当前节点的值
        while (i > 0 && data[(i - 1) / 2] < data[i]) {
            swap(data[(i - 1) / 2], data[i]);
            i = (i - 1) / 2;
        }
    }

    //向二叉树的底部移动
    void _shiftDown(int i) {
        assert(i >= 0);
        //有左子节点
        while (2 * i + 1 < count) {
            //判断有无右子节点
            int k = 2 * i + 1;
            //选择左右子节点中较大的那个
            if (k + 1 < count && data[k] < data[k + 1]) {
                k++;
            }

            //与子节点交换位置
            if (data[i] >= data[k]) {
                break;
            }
            swap(data[i], data[k]);
            i = k;
        }

    }

public:
    MaxHeap(int n) : capacity(n) {
        data = new int[n];
        count = 0;
    }

    /**
     * 对数组转成堆结构 heapify过程
     * 时间复杂度O(n)
     * 缺点：额外开辟O(n)的空间
     */
    MaxHeap(int arr[], int n) {
        data = new int[n];
        capacity = n;
        count = n;
        for (int i = 0; i < n; ++i) {
            data[i] = arr[i];
        }
        //heapify过程：从第一个非叶子结点(最后一个含有子节点的节点)开始进行shiftDown操作
        for (int j = (count - 2) / 2; j >= 0; --j) {
            _shiftDown(j);
        }
    }

    ~MaxHeap() {
        delete[]data;
    }

    //入堆
    void insert(int k) {
        //将元素插入到数组末尾
        data[count] = k;
        //上移元素
        _shiftUp(count);
        count++;
    }

    //出堆
    int extract() {
        assert(count > 0);
        if (count == 1) {
            count--;
            return data[0];
        }
        //交换根节点元素与最后一个元素的值,且count--
        int e = data[0];
        swap(data[0], data[--count]);
        //根节点向下移动
        _shiftDown(0);
        return e;
    }

    bool isEmpty() {
        return count;
    }

    int size() {
        return count;
    }

    friend ostream &operator<<(ostream &output, MaxHeap &maxHeap) {
        output << "size=" << maxHeap.count << endl;
        int lineLabel = 0;
        for (int i = 0; i < maxHeap.count; ++i) {
            output << maxHeap.data[i] << " ";
            if (i == lineLabel) {
                output << endl;
                lineLabel = 2 * i + 2;
            }
        }
        return output;
    }
};

#endif //ALGORITHM_MAXHEAP_H
