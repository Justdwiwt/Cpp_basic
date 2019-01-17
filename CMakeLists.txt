cmake_minimum_required(VERSION 3.6.2)

project(cppTestProject)

#编译器相关设置
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "c++")         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS "-Wall")                  # 开启所有警告

add_custom_target(cmake-build-debug)

add_executable(cppTestProject
        src/algorithm/basic.cpp
        src/algorithm/InsertSort.cpp
        src/algorithm/QuickSort.cpp
        src/algorithm/BubbleSort.cpp
        src/algorithm/HeapSort.cpp
        src/algorithm/MergeSort.cpp
        src/algorithm/main.cpp
        src/algorithm/Sales_data.h
        src/basic/ToHex.h
        src/algorithm/Shell.cpp
        src/algorithm/Astar.cpp
        src/algorithm/Astar.h
        src/algorithm/HuffmanTree.cpp
        src/leetcode/Lbd.h
        src/leetcode/104.cpp
        src/leetcode/344.cpp
        src/leetcode/292.cpp
        src/leetcode/20.cpp
        src/leetcode/728.cpp
        src/leetcode/709.cpp
        src/leetcode/704.cpp
        src/leetcode/707.cpp
        src/leetcode/622.cpp
        src/leetcode/144.cpp
        src/leetcode/141.cpp
        src/leetcode/155.cpp
        src/leetcode/148.cpp
        src/leetcode/206.cpp)
