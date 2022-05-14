//
// Created by Opynicus on 2022/5/14.
//

#ifndef OSLAB2__BUFFER_H_
#define OSLAB2__BUFFER_H_
#include <vector>
#include <queue>

constexpr int BUFFERSIZE = 8;

int gen_num = 0;

typedef struct Buffer {
  std::vector<int> content;
  int size;
  int empty, full;
  int producer_pos, consumer_pos;
  std::queue<int> EMPTY, FULL;
} Buffer;

#endif //OSLAB2__BUFFER_H_
