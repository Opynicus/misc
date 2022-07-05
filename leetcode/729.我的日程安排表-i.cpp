/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
class MyCalendar {
 public:
  MyCalendar() {}

  bool book(int start, int end) {
    for (auto &[l, r] : booked) {
      if (l < end && start < r) {
        return false;
      }
    }
    booked.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> booked;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
