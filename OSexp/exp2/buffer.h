//
// Created by Opynicus on 2022/4/10.
//

#ifndef LAB2_BUFFER_H
#define LAB2_BUFFER_H
#include<vector>
#include <mutex>
#include <condition_variable>
/*
    Buffer
*/
typedef struct SharedBuffer {
    std::vector<int> BufferQueue;
    int consumerPos;
    int  producerPos;
    std::condition_variable NotEmpty;
    std::condition_variable NotFull;
    std::mutex mtx;
};
#endif //LAB2_BUFFER_H
