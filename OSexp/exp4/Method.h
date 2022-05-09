//
// Created by Opynicus on 2022/5/2.
//

#ifndef OSLAB4_METHOD_H
#define OSLAB4_METHOD_H

#include "Fifo.h"
#include "Lru.h"

enum Permutation {
  FIFO, LRU
};

class Method {
 public:
  Fifo fifo;
  Lru lru;
  Method(int permutation, int _capacity, std::vector<int> test_case);
  void startPermutationjob();
 private:
  std::vector<int> test_case;
  int permutation;
};

#endif //OSLAB4_METHOD_H
