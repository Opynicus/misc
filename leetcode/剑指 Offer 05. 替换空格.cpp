// @algorithm @lc id=100280 lang=cpp
// @title ti-huan-kong-ge-lcof
class Solution {
 public:
  string replaceSpace(string s) {
    int left = 0;
    string res = "";
    for (auto i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        int len = i - left;
        string tmp(s, left, len);
        res += tmp;
        res += "%20";
        left = i + 1;
      }
    }
    int len = s.length() - left;
    string tmp(s, left, len);
    res += tmp;
    return res;
  }
};