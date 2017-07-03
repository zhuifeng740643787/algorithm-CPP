#include <iostream>
#include <vector>
#include <math.h>


#include "UnionFind/UnionFind.h"
#include "UnionFind/UnionFind2.h"
#include "UnionFind/UnionFind3.h"
#include "UnionFind/UnionFind4.h"
#include "UnionFind/UnionFind5.h"
#include "Helper/TestHelper.h"

using namespace std;

void test1(int n) {
    srand(time(NULL));
    UnionFind *uf = new UnionFind(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        uf->unionElements(a, b);
    }
    for (int j = 0; j < n; ++j) {
        int a = rand() % n;
        int b = rand() % n;
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    cout << uf;
    cout << "n=" << n << " time=" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    delete uf;
}

void test2(int n) {
    srand(time(NULL));
    UnionFind2 *uf = new UnionFind2(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        uf->unionElements(a, b);
    }
    for (int j = 0; j < n; ++j) {
        int a = rand() % n;
        int b = rand() % n;
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    cout << uf;
    cout << "n=" << n << " time=" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    delete uf;
}

void test3(int n) {
    srand(time(NULL));
    UnionFind3 *uf = new UnionFind3(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        uf->unionElements(a, b);
    }
    for (int j = 0; j < n; ++j) {
        int a = rand() % n;
        int b = rand() % n;
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    cout << uf;
    cout << "n=" << n << " time=" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    delete uf;
}
void test4(int n) {
    srand(time(NULL));
    UnionFind4 *uf = new UnionFind4(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        uf->unionElements(a, b);
    }
    for (int j = 0; j < n; ++j) {
        int a = rand() % n;
        int b = rand() % n;
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    cout << uf;
    cout << "n=" << n << " time=" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    delete uf;
}
void test5(int n) {
    srand(time(NULL));
    UnionFind5 *uf = new UnionFind5(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        uf->unionElements(a, b);
    }
    for (int j = 0; j < n; ++j) {
        int a = rand() % n;
        int b = rand() % n;
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    cout << uf;
    cout << "n=" << n << " time=" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    delete uf;
}
int main() {
    for (int i = 10; i <= 10000000; i *= 10) {
//        test1(i);
//        test2(i);
        test3(i);
        test4(i);
        test5(i);
        cout<<endl;
    }
}
