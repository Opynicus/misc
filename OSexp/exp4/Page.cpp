//
// Created by Opynicus on 2022/5/2.
//

#include "Page.h"


void Page::info() const {
    std::cout << "total hit cnt: " << cnt << std::endl;
    std::cout << "miss cnt: " << miss_cnt << std::endl;
    std::cout << "miss rate: " << (float)miss_cnt / (float)cnt << std::endl;
}
