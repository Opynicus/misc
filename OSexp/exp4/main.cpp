#include "Method.h"

int main() {
    std::vector<int> test_case1 = { 3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4 }; //FIFO
    std::vector<int> test_case2 = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 }; //LRU
    auto fifo_method = Method(FIFO, 3);
    fifo_method.initTestCase(test_case1);
    std::cout << "FIFO:" << std::endl;
    for (auto i:fifo_method.test_case) {
        fifo_method.fifo.operation(i);
    }
    fifo_method.fifo.info();

    auto lru_method = Method(LRU, 3);
    lru_method.initTestCase(test_case2);
    std::cout << "LRU:" << std::endl;
    for (auto i:lru_method.test_case) {
        lru_method.lru.operation(i);
    }
    lru_method.lru.info();

    return 0;
}
