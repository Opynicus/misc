class CQueue {
 private:
  stack<int> in_stack, out_stack;

 public:
  CQueue() {}

  void appendTail(int value) { in_stack.push(value); }

  int deleteHead() {
    if (out_stack.empty()) {
      if (in_stack.empty()) {
        return -1;
      }
      while (!in_stack.empty()) {
        out_stack.push(in_stack.top());
        in_stack.pop();
      }
    }
    int value = out_stack.top();
    out_stack.pop();
    return value;
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */