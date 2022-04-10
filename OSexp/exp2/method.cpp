//
// Created by Opynicus on 2022/4/10.
//

#include <iostream>
#include "method.h"
#include <thread>

SharedBuffer buff;

void Init(SharedBuffer *buffer) {
    buffer->producerPos = 0; // 初始化产品写入位置.
    buffer->consumerPos = 0; // 初始化产品读取位置.
    (buffer->BufferQueue).resize(buffSize);
}

void Producer(SharedBuffer *buffer, int item) {
    std::unique_lock<std::mutex> lock(buffer->mtx);
    while (((buffer->producerPos + 1) % buffSize) == buffer->consumerPos) { //缓冲区满了
        std::cout << "Producer is waiting..." << std::endl;
        (buffer->NotFull).wait(lock); // 生产者开始等待
    }

    buffer->BufferQueue[buffer->producerPos] = item; // 产生数据
    (buffer->producerPos)++; // pos++

    if (buffer->producerPos == buffSize) // 写入位置若是在队列最后则重新设置为初始位置.
        buffer->producerPos = 0;

    (buffer->NotEmpty).notify_all(); // 唤醒消费者
}

int Consumer(SharedBuffer *buffer) {
    int item;
    std::unique_lock<std::mutex> lock(buffer->mtx);
    // buffer块空了，等待
    while (buffer->producerPos == buffer->consumerPos) {
        std::cout << "Consumer is waiting..." << std::endl;
        (buffer->NotEmpty).wait(lock); // 消费者开始等待
    }

    item = buffer->BufferQueue[buffer->consumerPos]; // 消费
    (buffer->consumerPos)++; // pos++

    if (buffer->consumerPos >= buffSize) // 读取位置若移到最后，则重新置位.
        buffer->consumerPos = 0;

    (buffer->NotFull).notify_all(); // 唤醒生产者

    return item; // 返回产品.
}

void ProducerTask() {
    for (int i = 1; i <= proNum; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "Produce the item " << i << " ..." << std::endl;
        Producer(&buff , i); // 循环生产 proNum 个产品.
    }
}

void ConsumerTask() {
    static int cnt = 0;
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int item = Consumer(&buff); // 消费一个产品.
        std::cout << "Consume the item " << item << " ..." << std::endl;
        cnt++;
        if (cnt == proNum) break; // 如果产品消费个数为 proNum, 则退出.
    }
}

void StartJob() {
    Init(&buff);
    std::cout<<"BufferSize is " << buffSize << ", and items to be produced is " << proNum << " in total" << std::endl;
    std::thread producer(ProducerTask); // 创建生产者线程.
    std::thread consumer(ConsumerTask); // 创建消费之线程.
    producer.join();
    consumer.join();
}

