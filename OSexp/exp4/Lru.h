//
// Created by Opynicus on 2022/5/2.
//

#ifndef OSLAB4_LRU_H
#define OSLAB4_LRU_H

#include "Page.h"

class Lru : public Page {
 public:
  explicit Lru(int _capacity);
  void operation(int vis) override;
 private:
  int size;
  std::list<int> list;
};

#endif //OSLAB4_LRU_H
