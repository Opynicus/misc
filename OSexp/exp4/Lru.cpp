//
// Created by Opynicus on 2022/5/2.
//

#include "Lru.h"

Lru::Lru(int _capacity) {
    capacity = _capacity;
    cnt = 0;
    miss_cnt = 0;
    size = 0;
}

void Lru::operation(int vis) {
    cnt++;
    if (size < capacity) {
        list.push_back(vis);
        miss_cnt++;
        size++;
    } else {
        if (!std::count(list.begin(), list.end(), vis)) {
            miss_cnt++;
            list.pop_front();
            list.push_back(vis);
        } else {
            list.remove(vis);
            list.push_back(vis);
        }
    }
}
