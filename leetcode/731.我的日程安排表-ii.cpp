/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start
class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto &[left, right] : overlaps) {
      if (left < end && start < right) {
        return false;
      }
    }
    for (auto &[left, right] : booked) {
      if (left < end && start < right) {
        overlaps.emplace_back(max(left, start), min(right, end));
      }
    }
    booked.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> booked;
  vector<pair<int, int>> overlaps;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
