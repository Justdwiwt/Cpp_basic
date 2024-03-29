cmake_minimum_required(VERSION 3.6.2)

project(cppTestProject)

#编译器相关设置
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "c++")                 # 显示指定使用的C++编译器
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
        src/leetcode/461.cpp src/leetcode/17.cpp src/leetcode/494.cpp src/algorithm/Trie.cpp src/algorithm/TopologicalSort.cpp
        src/algorithm/BitMap.cpp src/algorithm/BitMap.h src/leetcode/8.cpp src/leetcode/16.cpp src/leetcode/230.cpp
        src/leetcode/215.cpp src/leetcode/53.cpp src/leetcode/142.cpp src/leetcode/108.cpp src/leetcode/19.cpp
        src/leetcode/101.cpp src/leetcode/105.cpp src/leetcode/76.cpp src/leetcode/125.cpp src/leetcode/208.cpp
        src/leetcode/412.cpp src/leetcode/102.cpp src/leetcode/162.cpp src/leetcode/347.cpp src/leetcode/1195.cpp
        src/leetcode/538.cpp src/leetcode/399.cpp src/leetcode/543.cpp src/leetcode/617.cpp src/leetcode/560.cpp
        src/leetcode/1026.cpp src/leetcode/6.cpp src/leetcode/23.cpp src/leetcode/31.cpp src/leetcode/58.cpp
        src/leetcode/198.cpp src/leetcode/55.cpp src/leetcode/32.cpp src/leetcode/278.cpp src/leetcode/337.cpp
        src/leetcode/338.cpp src/leetcode/345.cpp src/leetcode/350.cpp src/leetcode/357.cpp src/leetcode/368.cpp
        src/leetcode/397.cpp src/leetcode/10.cpp src/leetcode/30.cpp src/leetcode/47.cpp src/leetcode/44.cpp
        src/leetcode/24.cpp src/leetcode/25.cpp src/leetcode/33.cpp src/leetcode/941.cpp src/leetcode/498.cpp
        src/leetcode/821.cpp src/leetcode/748.cpp src/leetcode/405.cpp src/leetcode/409.cpp src/leetcode/744.cpp
        src/leetcode/50.cpp src/leetcode/828.cpp src/leetcode/643.cpp src/leetcode/165.cpp src/leetcode/91.cpp
        src/leetcode/515.cpp src/leetcode/523.cpp src/leetcode/884.cpp src/leetcode/938.cpp src/leetcode/926.cpp
        src/leetcode/306.cpp src/leetcode/673.cpp src/leetcode/384.cpp src/leetcode/1185.cpp src/leetcode/491.cpp
        src/leetcode/639.cpp src/leetcode/600.cpp src/leetcode/129.cpp src/leetcode/92.cpp src/leetcode/80.cpp
        src/leetcode/509.cpp src/leetcode/530.cpp src/leetcode/859.cpp src/leetcode/242.cpp src/leetcode/977.cpp
        src/leetcode/112.cpp src/leetcode/844.cpp src/leetcode/738.cpp src/leetcode/111.cpp src/leetcode/1190.cpp
        src/leetcode/606.cpp src/leetcode/503.cpp src/leetcode/590.cpp src/leetcode/589.cpp src/leetcode/664.cpp
        src/leetcode/761.cpp src/leetcode/97.cpp src/leetcode/273.cpp src/leetcode/564.cpp src/leetcode/730.cpp
        src/leetcode/906.cpp src/leetcode/466.cpp src/leetcode/956.cpp src/leetcode/882.cpp src/leetcode/883.cpp
        src/leetcode/1266.cpp src/leetcode/812.cpp src/leetcode/598.cpp src/leetcode/788.cpp src/leetcode/893.cpp
        src/leetcode/764.cpp src/leetcode/799.cpp src/leetcode/672.cpp src/leetcode/629.cpp src/leetcode/335.cpp
        src/leetcode/1187.cpp src/leetcode/920.cpp src/leetcode/798.cpp src/leetcode/789.cpp src/leetcode/691.cpp
        src/leetcode/837.cpp src/model/TmpPtr.cpp src/leetcode/1.cpp src/leetcode/2.cpp src/leetcode/4.cpp
        src/leetcode/5.cpp src/leetcode/7.cpp src/leetcode/9.cpp src/leetcode/11.cpp src/leetcode/13.cpp
        src/leetcode/21.cpp src/leetcode/22.cpp src/leetcode/26.cpp src/leetcode/27.cpp src/leetcode/35.cpp
        src/leetcode/36.cpp src/leetcode/37.cpp src/leetcode/38.cpp src/leetcode/40.cpp src/leetcode/42.cpp
        src/leetcode/43.cpp src/leetcode/45.cpp src/leetcode/46.cpp src/leetcode/48.cpp src/leetcode/49.cpp
        src/leetcode/51.cpp src/leetcode/52.cpp src/leetcode/54.cpp src/leetcode/57.cpp src/leetcode/60.cpp
        src/leetcode/61.cpp src/leetcode/62.cpp src/leetcode/63.cpp src/leetcode/64.cpp src/leetcode/65.cpp
        src/leetcode/66.cpp src/leetcode/68.cpp src/leetcode/69.cpp src/leetcode/355.cpp src/leetcode/70.cpp
        src/leetcode/71.cpp src/leetcode/72.cpp src/leetcode/73.cpp src/leetcode/74.cpp src/leetcode/77.cpp
        src/leetcode/78.cpp src/leetcode/81.cpp src/leetcode/82.cpp src/leetcode/83.cpp src/leetcode/84.cpp
        src/leetcode/85.cpp src/leetcode/86.cpp src/leetcode/87.cpp src/leetcode/88.cpp src/leetcode/90.cpp
        src/leetcode/95.cpp src/leetcode/96.cpp src/leetcode/98.cpp src/leetcode/99.cpp src/leetcode/100.cpp
        src/leetcode/103.cpp src/leetcode/106.cpp src/leetcode/107.cpp src/leetcode/109.cpp src/leetcode/110.cpp
        src/leetcode/113.cpp src/leetcode/114.cpp src/leetcode/115.cpp src/leetcode/116.cpp src/leetcode/117.cpp
        src/leetcode/118.cpp src/leetcode/119.cpp src/leetcode/120.cpp src/leetcode/121.cpp src/leetcode/122.cpp
        src/leetcode/123.cpp src/leetcode/124.cpp src/leetcode/126.cpp src/leetcode/127.cpp src/leetcode/130.cpp
        src/leetcode/132.cpp src/leetcode/133.cpp src/leetcode/134.cpp src/leetcode/135.cpp src/leetcode/136.cpp
        src/leetcode/137.cpp src/leetcode/138.cpp src/leetcode/140.cpp src/leetcode/143.cpp src/leetcode/145.cpp
        src/leetcode/147.cpp src/leetcode/149.cpp src/leetcode/150.cpp src/leetcode/151.cpp src/leetcode/152.cpp
        src/leetcode/153.cpp src/leetcode/154.cpp src/leetcode/164.cpp src/leetcode/166.cpp src/leetcode/167.cpp
        src/leetcode/168.cpp src/leetcode/169.cpp src/leetcode/171.cpp src/leetcode/172.cpp src/leetcode/173.cpp
        src/leetcode/174.cpp src/leetcode/187.cpp src/leetcode/188.cpp src/leetcode/190.cpp src/leetcode/191.cpp
        src/leetcode/199.cpp src/leetcode/200.cpp src/leetcode/202.cpp src/leetcode/203.cpp src/leetcode/204.cpp
        src/leetcode/205.cpp src/leetcode/207.cpp src/leetcode/209.cpp src/leetcode/210.cpp src/leetcode/211.cpp
        src/leetcode/212.cpp src/leetcode/213.cpp src/leetcode/214.cpp src/leetcode/216.cpp src/leetcode/217.cpp
        src/leetcode/218.cpp src/leetcode/219.cpp src/leetcode/220.cpp src/leetcode/221.cpp src/leetcode/222.cpp
        src/leetcode/223.cpp src/leetcode/225.cpp src/leetcode/227.cpp src/leetcode/228.cpp src/leetcode/231.cpp
        src/leetcode/232.cpp src/leetcode/235.cpp src/leetcode/236.cpp src/leetcode/237.cpp
        src/leetcode/3017.cpp
        src/leetcode/3016.cpp
        src/leetcode/3015.cpp
        src/leetcode/3014.cpp
        src/leetcode/3013.cpp)
