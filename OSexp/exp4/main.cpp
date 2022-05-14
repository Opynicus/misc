/*
 * @Author: Opynicus
 * @Date: 2022-05-02 16:35:13
 * @LastEditTime: 2022-05-14 20:47:09
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \OSexp\exp4\main.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
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
