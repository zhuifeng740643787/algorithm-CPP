//
// Created by 宫宜栋 on 2017/6/27.
//

#ifndef ALGORITHM_MINHEAP_H
#define ALGORITHM_MINHEAP_H

#include <iostream>

using namespace std;

/**
 * 最小堆
 */
template<typename Item>
class MinHeap {

private:
    int capacity;//容量
    int count;//个数
    Item *data;//数据

    //上移索引处的元素
    void _shiftUp(int index) {

        while (index > 0 && data[index] < data[(index - 1) / 2]) {
            swap(data[index], data[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    //下移索引处的元素
    void _shiftDown(int index) {
        //有子节点
        while (2 * index + 1 < count) {
            int childIndex = 2 * index + 1;
            if (childIndex + 1 < count && data[childIndex] > data[childIndex + 1]) {
                childIndex++;
            }
            if(data[index] < data[childIndex]) {
                break;
            }
            swap(data[index], data[childIndex]);
            index = childIndex;
        }

    }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        count = 0;
        data = new Item[capacity];
    }

    ~MinHeap() {
        delete[] data;
    }

    void insert(Item item) {
        data[count++] = item;
        _shiftUp(count - 1);
    }

    Item extract() {
        if (empty()) {
            return Item();
        }
        if (count == 1) {
            count = 0;
            return data[0];
        }
        Item item = data[0];

        swap(data[0], data[--count]);

        _shiftDown(0);
        return item;
    }

    bool empty() {
        return count == 0;
    }

};

#endif //ALGORITHM_MINHEAP_H
