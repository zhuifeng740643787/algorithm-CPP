//
// Created by 宫宜栋 on 2017/6/27.
//

#ifndef ALGORITHM_MININDEXHEAP_H
#define ALGORITHM_MININDEXHEAP_H

#include <iostream>
#include <map>

using namespace std;

/**
 * 最小索引堆
 */
template<typename Item>
class MinIndexHeap {
private:
    int capacity;
    int count;
    int *indexes;
    map<int, int> reverseIndexes;
    Item *data;

    void _shiftUp(int i) {
        //父节点的元素大于该节点元素时，进行交换
        while (i > 0 && data[indexes[(i - 1) / 2]] > data[indexes[i]]) {
            swap(indexes[i], indexes[(i - 1) / 2]);
            reverseIndexes[indexes[i]] = i;
            reverseIndexes[indexes[(i - 1) / 2]] = (i - 1) / 2;
            i = (i - 1) / 2;
        }
    }

    void _shiftDown(int i) {
        //含有子节点
        while (2 * i + 1 < count) {
            int childIndex = 2 * i + 1;
            if (childIndex + 1 < count && data[indexes[childIndex]] > data[indexes[childIndex + 1]]) {
                childIndex++;
            }
            if (data[indexes[childIndex]] >= data[indexes[i]]) {
                break;
            }

            swap(indexes[i], indexes[childIndex]);
            reverseIndexes[indexes[i]] = i;
            reverseIndexes[indexes[childIndex]] = childIndex;
            i = childIndex;
        }
    }

public:
    MinIndexHeap(int capacity) {
        this->capacity = capacity;
        count = 0;
        indexes = new int[capacity];
        data = new Item[capacity];

    }

    ~MinIndexHeap() {
        delete[] indexes;
        delete[] data;
    }

    //插入
    void insert(int index, Item item) {
        if (getI(index) != -1) {
            cout << "已存在" << endl;
            return;
        }

        indexes[count] = index;
        reverseIndexes[indexes[count]] = count;
        count++;
        data[index] = item;
        //上移最后一个元素
        _shiftUp(count - 1);
    }

    //出堆
    Item extractItem() {
        if (empty()) {
            return Item();
        }

        Item item = data[indexes[0]];
        swap(indexes[0], indexes[count - 1]);
        reverseIndexes[indexes[0]] = 0;
        reverseIndexes.erase(reverseIndexes.find(indexes[count - 1]));
        count--;
        _shiftDown(0);
        return item;
    }

    //出堆
    int extractIndex() {
        if (empty()) {
            return -1;
        }
        int index = indexes[0];
        swap(indexes[0], indexes[count - 1]);
        reverseIndexes[indexes[0]] = 0;
        reverseIndexes.erase(reverseIndexes.find(indexes[count - 1]));
        count--;
        _shiftDown(0);
        return index;
    }

    Item getData(int index) {
        if(getI(index) != -1) {
            return Item();
        }
        return data[index];
    }

    //修改索引的值
    void change(int index, Item item) {
        int i = getI(index);
        if (i == -1) {
            cout << "未找到的索引" << endl;
            return;
        }

        indexes[i] = index;
        data[index] = item;
        _shiftUp(i);
        _shiftDown(i);
    }

    //利用反向查找，获取索引index在indexes[]数组中的位置
    int getI(int index) {
        map<int, int>::iterator i = reverseIndexes.find(index);
        if (i == reverseIndexes.end()) {
            return -1;
        } else {
            return i->second;
        }
    }

    //判断索引index是否存在
    bool contain(int index) {
        return getI(index) != -1;
    }
    void showIndexes() {
        for (int i=0; i< count ; i++){
           cout<<indexes[i]<<"  ";
        }
        cout << endl;
    }
    void showReverseIndexes() {
        for (map<int, int>::iterator it = reverseIndexes.begin(); it != reverseIndexes.end(); ++it) {
            cout << it->first << "-" << it->second << " ";
        }
        cout << endl;
    }

    bool empty() {
        return count == 0;
    }

};

#endif //ALGORITHM_MININDEXHEAP_H
