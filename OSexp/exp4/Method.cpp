//
// Created by Opynicus on 2022/5/2.
//

#include "Method.h"

Method::Method(int permutation, int _capacity): fifo(_capacity), lru(_capacity) {
    if (permutation == FIFO) {
        this->permutation = FIFO;
    } else if (permutation == LRU) {
        this->permutation = LRU;
    }
    else {
        std::cout << "Error" << std::endl;

    }
}

void Method::initTestCase(std::vector<int> test_case) {
    this->test_case = std::move(test_case);
}
