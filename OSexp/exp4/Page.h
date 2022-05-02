//
// Created by Opynicus on 2022/5/2.
//

#ifndef OSLAB4_PAGE_H
#define OSLAB4_PAGE_H

#include <queue>
#include <unordered_map>
#include <list>
#include <iostream>


class Page {
public:
    virtual void operation(int) = 0;
    void info() const;

protected:
    int capacity{};
    int cnt{};
    int miss_cnt{};
};


#endif //OSLAB4_PAGE_H
