#include "Buffer.h"
#include <iostream>
#include <cstring>

void producer(int produce, Buffer &buf) {
  buf.content[buf.producer_pos] = produce;
  buf.producer_pos = (buf.producer_pos + 1) % buf.size;
  buf.full++;
}

void consumer(Buffer &buf) {
  buf.content[buf.consumer_pos] = -1;
  buf.consumer_pos = (buf.consumer_pos + 1) % buf.size;
  buf.empty++;
}

void checkFull(Buffer &buf) {
  if (buf.full <= 0 && buf.EMPTY.size() > 0) {
    buf.EMPTY.pop();
    consumer(buf);
  }
}

void checkEmpty(Buffer &buf) {
  if (buf.empty <= 0 && buf.FULL.size() > 0) {
    int val = buf.FULL.front();
    buf.FULL.pop();
    producer(val, buf);
  }
}

void producerTask(Buffer &buf) {
  int produceNum = gen_num;
  gen_num++;
  buf.empty--;
  if (buf.empty < 0) {
    std::cout << "producer " << -buf.empty << " waiting..." << std::endl;
    buf.FULL.push(produceNum);
  } else {
    producer(produceNum, buf);
    checkFull(buf);
  }
}

void consumerTask(Buffer &buf) {
  buf.full--;
  if (buf.full < 0) {
    std::cout << "consumer " << -buf.full << " waiting..." << std::endl;
    buf.EMPTY.push(-1);
  } else {
    consumer(buf);
    checkEmpty(buf);
  }
}


int main() {
  // 初始化buffer
  Buffer buf;
  buf.content.resize(BUFFERSIZE);
  buf.empty = BUFFERSIZE;
  buf.full = 0;
  buf.size = BUFFERSIZE;
  buf.producer_pos = 0;
  buf.consumer_pos = 0;
  while (true) {
    char cmd[100];
    std::cin.getline(cmd, 100);
    if (strcmp(cmd, "p") == 0) {
      producerTask(buf);
    } else if (strcmp(cmd, "c") == 0) {
      consumerTask(buf);
    } else if (strcmp(cmd, "s") == 0) {
      std::cout << "Buffer Content: ";
      for (int i : buf.content) {
        std::cout << i << ' ';
      }
      std::cout << std::endl;
      std::cout << "Buffer empty size: " << buf.empty << std::endl;
      std::cout << "Buffer full size: " << buf.full << std::endl;
      std::cout << "Producer pos: " << buf.producer_pos << std::endl;
      std::cout << "Consumer pos: " << buf.consumer_pos << std::endl;
    } else {
      break;
    }
  }
  return 0;
}
