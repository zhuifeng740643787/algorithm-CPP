//
// Created by 宫宜栋 on 2017/6/20.
//

#ifndef ALGORITHM_MAXINDEXHEAP_H
#define ALGORITHM_MAXINDEXHEAP_H

#include <iostream>
#include <cassert>
#include "../Helper/TestHelper.h"

using namespace std;

/**
 * 最大索引堆
 */
class MaxIndexHeap {
private:
    int capacity;
    int count;
    int *indexes;
    int *data;
    int *reverseIndexes;//反向索引，便于查找及更新操作
                        // indexes[i] = j,  reverseIndexes[j] = i,
                        // 即 indexes[reverseIndexes[j]] = j, reverseIndexes[indexes[i]] = i

    void _shiftUp(int i) {
        //判断父节点
        while ((i - 1) / 2 >= 0 && data[indexes[(i - 1) / 2]] < data[indexes[i]]) {
            swap(indexes[(i - 1) / 2], indexes[i]);
            //更新反向索引数组数据
            reverseIndexes[indexes[(i-1)/2]] = (i-1)/2;
            reverseIndexes[indexes[i]] = i;
            i = (i - 1) / 2;
        }
    }

    void _shiftDown(int i) {
        //判断子节点
        while (2 * i + 1 < count) {
            int j = 2 * i + 1;
            if ((j + 1) < count && (data[indexes[j + 1]] > data[indexes[j]])) {
                j = j + 1;
            }
            if (data[indexes[j]] <= data[indexes[i]]) {
                break;
            }
            swap(indexes[i], indexes[j]);
            reverseIndexes[indexes[i]] = i;
            reverseIndexes[indexes[j]] = j;
            i = j;
        }
    }

    //增大容量
    void _enlargeCapacity() {
        if(count < capacity) {
            return;
        }
        //扩大两倍
        capacity = capacity<<1;
        int *newIndexes = new int[capacity];
        int *newData = new int[capacity];
        int *newReverseIndexes = new int[capacity];

        for (int i = 0; i < count ; ++i) {
            newIndexes[i] = indexes[i];
            newReverseIndexes[i] = reverseIndexes[i];
            newData[indexes[i]] = data[indexes[i]];
        }

        for (int j = count; j < capacity ; ++j) {
            newReverseIndexes[j] = -1;
        }

        delete[] indexes;
        delete[] reverseIndexes;
        delete[] data;

        indexes = newIndexes;
        reverseIndexes = newReverseIndexes;
        data = newData;
    }

    //个数小于等于容量的1/4时，缩小容量至1/2
    void _shrinkCapacity() {
        if(count > capacity>>2) {
            return;
        }

        //缩小至1/2
        capacity = capacity>>1;
        int *newIndexes = new int[capacity];
        int *newData = new int[capacity];
        int *newReverseIndexes = new int[capacity];

        for (int i = 0; i < count ; ++i) {
            newIndexes[i] = indexes[i];
            newReverseIndexes[i] = reverseIndexes[i];
            newData[indexes[i]] = data[indexes[i]];
        }
        delete[] indexes;
        delete[] reverseIndexes;
        delete[] data;

        indexes = newIndexes;
        reverseIndexes = newReverseIndexes;
        data = newData;
    }

public:
    MaxIndexHeap(int n) {
        capacity = n;
        count = 0;
        indexes = new int[n];
        data = new int[n];
        reverseIndexes = new int[n];
        for (int i = 0; i < capacity; ++i) {
            reverseIndexes[i] = -1;
        }
    }

    ~MaxIndexHeap() {
        delete[] indexes;
        delete[] reverseIndexes;
        delete[] data;
    }



    // data 索引i位置插入k元素
    void insert(int i, int k) {
        assert(i >= 0);
        //元素个数超出容量时，扩容
        _enlargeCapacity();

        //检查是否存在i
        if (getIndexPosition(i) != -1) {
            cout<<"已存在i:"<<i<<endl;
            return;
        }

        indexes[count] = i;
        reverseIndexes[indexes[count]] = count;
        count++;
        data[i] = k;
        _shiftUp(count - 1);
    }

    //出堆（索引）
    int extractIndex() {
        assert(count > 0);
        //缩小容量
        _shrinkCapacity();
        if (count == 1) {
            reverseIndexes[indexes[0]] = -1;
            return indexes[--count];
        }
        int e = indexes[0];
        swap(indexes[0], indexes[count-1]);
        reverseIndexes[indexes[0]] = 0;
        reverseIndexes[indexes[count - 1]] = count - 1;
        count--;
        _shiftDown(0);
        return e;
    }
    //出堆
    int extract() {
        assert(count > 0);
        //缩小容量
        _shrinkCapacity();
        if (count == 1) {
            reverseIndexes[indexes[0]] = -1;
            return data[indexes[--count]];
        }
        int e = data[indexes[0]];
        swap(indexes[0], indexes[count-1]);
        reverseIndexes[indexes[0]] = 0;
        reverseIndexes[indexes[count - 1]] = count - 1;
        count--;
        _shiftDown(0);
        return e;
    }

    //修改索引i的值
    void change(int i, int k) {
        //找到i元素在indexes数组中的位置
        int index = getIndexPosition(i);
        if(index == -1) {
            cout<<"元素未找到"<<endl;
            return;
        }
        data[i] = k;
        //对该位置进行shiftDown和shiftUp操作
        _shiftDown(index);
        _shiftUp(index);
    }

    int getIndexPosition(int i) {

//        for (int j = 0; j < count; ++j) {
//            if(indexes[j] == i) {
//                return j;
//            }
//        }
//        return -1;

        //反向查找
        return reverseIndexes[i];
    }
    //根据索引值获取值
    int getData(int i) {
        return data[i];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    int getCapacity() {
        return capacity;
    }
    //打印堆
    void printHeap() {
        cout<<"count="<<count<<" capacity="<<capacity<<endl;
        for (int i = 0; i < count; ++i) {
            cout << "i=" << i << " indexes[" << i << "]=" << indexes[i] << " data[" << indexes[i] << "]="
                 << data[indexes[i]] << endl;

        }
    }

    void showReverse() {
        for (int i = 0; i < capacity; ++i) {
            cout<<reverseIndexes[i]<<" ";
        }
        cout<<endl;
    }
};

#endif //ALGORITHM_MAXINDEXHEAP_H
