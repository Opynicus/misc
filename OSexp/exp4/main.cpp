#include "Method.h"

int main() {
  std::vector<int> test_case1 = {3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4}; //FIFO
  std::vector<int> test_case2 = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1}; //LRU
  auto fifo_method = Method(FIFO, 3, test_case1);
  fifo_method.startPermutationjob();
  fifo_method.fifo.info();

  auto lru_method = Method(LRU, 3, test_case2);
  lru_method.startPermutationjob();
  lru_method.lru.info();

  return 0;
}
