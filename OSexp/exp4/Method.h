//
// Created by Opynicus on 2022/5/2.
//

#ifndef OSLAB4_METHOD_H
#define OSLAB4_METHOD_H

#include "Fifo.h"
#include "Lru.h"

enum Permutation{
    FIFO, LRU
};

class Method {
public:
    Method(int permutation, int _capacity);
    void initTestCase(std::vector<int> test_case_);
    std::vector<int> test_case;
    int permutation;
    Fifo fifo;
    Lru lru;
};


#endif //OSLAB4_METHOD_H
