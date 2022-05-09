//
// Created by Opynicus on 2022/5/2.
//

#include "Method.h"

Method::Method(int permutation, int _capacity, std::vector<int> test_case) : fifo(_capacity), lru(_capacity) {
  if (permutation == FIFO) {
    this->permutation = FIFO;
    this->test_case = std::move(test_case);
  } else if (permutation == LRU) {
    this->permutation = LRU;
    this->test_case = std::move(test_case);
  } else {
    std::cout << "Error" << std::endl;

  }
}
void Method::startPermutationjob() {
  if (this->permutation == FIFO) {
    std::cout << "FIFO:" << std::endl;
    for (auto i : this->test_case) {
      this->fifo.operation(i);
    }
  } else if (this->permutation == LRU) {
    std::cout << "LRU:" << std::endl;
    for (auto i : this->test_case) {
      this->lru.operation(i);
    }
  } else {
    std::cout << "Unknown permutation Algo" << std::endl;
  }
}
