#ifndef CPPTESTPROJECT_LBD_H
#define CPPTESTPROJECT_LBD_H

#include <iostream>

static const auto init = []() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;

}();

#endif //CPPTESTPROJECT_LBD_H
