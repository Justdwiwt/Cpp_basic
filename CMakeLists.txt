cmake_minimum_required(VERSION 3.12)
project(cppTestProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(cppTestProject
        algorithm/basic.cpp
        algorithm/InsertSort.cpp
        algorithm/QuickSort.cpp
        algorithm/BubbleSort.cpp
        algorithm/HeapSort.cpp
        algorithm/MergeSort.cpp
        algorithm/main.cpp
        algorithm/Sales_data.h
        basic/ToHex.h algorithm/Shell.cpp algorithm/Astar.cpp algorithm/Astar.h algorithm/HuffmanTree.cpp)