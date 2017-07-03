//
// Created by 宫宜栋 on 2017/6/20.
//

#include <iostream>
#include "Heap/MaxHeap.h"
#include "Heap/MaxIndexHeap.h"

#include "Helper/TestHelper.h"

using namespace std;


int main() {
    int n = 10;
    int *arr = TestHelper::generateRandomArr(n, 0, 20);
    MaxIndexHeap *maxIndexHeap = new MaxIndexHeap(n);
    for (int i = 0; i < n; i++) {
        maxIndexHeap->insert(i, arr[i]);
    }
    maxIndexHeap->change(1, 8);
    maxIndexHeap->change(3, 22);
    while (!maxIndexHeap->isEmpty()) {
        int index = maxIndexHeap->extractIndex();
        cout<<index<<"-";
        cout<<maxIndexHeap->getData(index)<<endl;
    }
    cout<<endl;


}
