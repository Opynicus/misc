//
// Created by Opynicus on 2022/5/2.
//

#ifndef OSLAB4_FIFO_H
#define OSLAB4_FIFO_H


#include "Page.h"

class Fifo: public Page {
public:
    explicit Fifo(int _capacity);
    void operation(int vis) override;
private:
    std::unordered_map<int, bool> cache;
    std::queue<int> queue;
};


#endif //OSLAB4_FIFO_H
