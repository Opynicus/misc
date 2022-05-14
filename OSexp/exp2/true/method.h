//
// Created by Opynicus on 2022/4/10.
//

#include "buffer.h"
#ifndef LAB2_METHOD_H
#define LAB2_METHOD_H
static const int proNum = 30;   // 生产者需要产生的任务数量
static const int buffSize = 7; // buffer大小
void Init(SharedBuffer *buffer);// 初始化buffer
void Producer(SharedBuffer *buffer, int item); // 生产者
int Consumer(SharedBuffer *buffer); // 消费者
void ProducerTask(); //生产者任务
void ConsumerTask(); //消费者任务
void StartJob(); //开始作业
#endif //LAB2_METHOD_H
