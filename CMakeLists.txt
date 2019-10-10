cmake_minimum_required(VERSION 3.6.2)

project(cppTestProject)

#编译器相关设置
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "c++")         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS "-Wall")                  # 开启所有警告

add_custom_target(cmake-build-debug)

add_executable(cppTestProject
        src/algorithm/basic.cpp src/algorithm/InsertSort.cpp src/algorithm/QuickSort.cpp src/algorithm/BubbleSort.cpp
        src/algorithm/HeapSort.cpp src/algorithm/MergeSort.cpp src/algorithm/main.cpp src/algorithm/Sales_data.h
        src/basic/ToHex.h src/algorithm/Shell.cpp src/algorithm/Astar.cpp src/algorithm/Astar.h
        src/algorithm/HuffmanTree.cpp src/leetcode/Lbd.h src/leetcode/104.cpp src/leetcode/344.cpp
        src/leetcode/292.cpp src/leetcode/20.cpp src/leetcode/728.cpp src/leetcode/709.cpp
        src/leetcode/704.cpp src/leetcode/707.cpp src/leetcode/622.cpp src/leetcode/144.cpp
        src/leetcode/141.cpp src/leetcode/155.cpp src/leetcode/148.cpp src/leetcode/206.cpp
        src/leetcode/34.cpp src/leetcode/41.cpp src/leetcode/28.cpp src/basic/ns.cpp src/leetcode/18.cpp
        src/leetcode/146.cpp src/leetcode/406.cpp src/leetcode/39.cpp src/leetcode/79.cpp src/leetcode/301.cpp
        src/leetcode/160.cpp src/leetcode/59.cpp src/leetcode/89.cpp src/leetcode/94.cpp src/leetcode/131.cpp
        src/leetcode/179.cpp src/leetcode/3.cpp src/leetcode/14.cpp src/leetcode/29.cpp src/leetcode/12.cpp
        src/leetcode/297.cpp src/leetcode/647.cpp src/leetcode/739.cpp src/leetcode/67.cpp src/leetcode/93.cpp
        src/leetcode/1114.cpp src/leetcode/1117.cpp src/leetcode/1115.cpp src/leetcode/1116.cpp src/leetcode/15.cpp
        src/leetcode/139.cpp src/leetcode/229.cpp src/leetcode/300.cpp src/leetcode/343.cpp src/leetcode/380.cpp
        src/leetcode/460.cpp src/leetcode/470.cpp src/leetcode/540.cpp src/leetcode/648.cpp src/leetcode/677.cpp
        src/leetcode/784.cpp src/leetcode/785.cpp src/leetcode/852.cpp src/leetcode/860.cpp src/leetcode/868.cpp
        src/leetcode/984.cpp src/leetcode/985.cpp src/leetcode/1002.cpp src/leetcode/1021.cpp src/leetcode/201.cpp
        src/leetcode/224.cpp src/leetcode/233.cpp src/leetcode/274.cpp src/leetcode/275.cpp src/leetcode/LCP1.cpp
        src/leetcode/LCP2.cpp src/leetcode/LCP5.cpp src/leetcode/234.cpp src/leetcode/394.cpp src/leetcode/226.cpp
        src/leetcode/680.cpp src/leetcode/189.cpp src/leetcode/75.cpp src/leetcode/128.cpp src/leetcode/56.cpp
        src/leetcode/461.cpp src/leetcode/17.cpp src/leetcode/494.cpp src/algorithm/Trie.cpp src/algorithm/TopologicalSort.cpp src/algorithm/BitMap.cpp src/algorithm/BitMap.h)
