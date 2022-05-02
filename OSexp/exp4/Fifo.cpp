//
// Created by Opynicus on 2022/5/2.
//

#include "Fifo.h"

Fifo::Fifo(int _capacity) {
    capacity = _capacity;
    cnt = 0;
    miss_cnt = 0;
}

void Fifo::operation(int vis) {
    cnt++;
    if (!cache.count(vis)) {
        miss_cnt++;
        if (cache.size() == capacity) {
            auto p = queue.front();
            cache.erase(p);
            queue.pop();
        }
        queue.push(vis);
        cache[vis] = true;
    }
}
