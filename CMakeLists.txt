cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES search.cpp Sort/SelectionSort.h Helper/TestHelper.h Sort/InsertionSort.h Sort/BubbleSort.h Sort/MergeSort.h Sort/MergeBUSort.h Sort/QuickSortSingleWay.h Sort/QuickSortTwoWays.h Sort/QuickSortThreeWays.h Sort/HeapSort.h Heap/MaxHeap.h heap.cpp Heap/MaxIndexHeap.h Tree/BinarySearchMethod.h search.cpp)
#set(SOURCE_FILES search.cpp Helper/TestHelper.h Sort/InsertionSort.h Tree/BinarySearchMethod.h search.cpp Tree/BinarySearchTree.h Tree/RedBlackTree.h Tree/Treap.h Tree/Trie.h UnionFind/UnionFind.h)
#set(SOURCE_FILES unionfind.cpp Helper/TestHelper.h)
#set(SOURCE_FILES graph.cpp Helper/TestHelper.h Graph/DenseGraph.h Graph/SparseGraph.h Graph/ReadGraph.h Graph/Component.h Graph/Path.h Graph/ShortestPath.h MinumumSpanTree/Edge.h)
#set(SOURCE_FILES minimumspantree.cpp Helper/TestHelper.h MinumumSpanTree/MinHeap.h MinumumSpanTree/LazyPrimMST.h MinumumSpanTree/MinIndexHeap.h MinumumSpanTree/PrimMST.h MinumumSpanTree/UnionFind.h MinumumSpanTree/KruskalMST.h ShortestPath/Dijkstra.h)
set(SOURCE_FILES shotestpath.cpp ShortestPath/BellmanFord.h)
add_executable(algorithm ${SOURCE_FILES})