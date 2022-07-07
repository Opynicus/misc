/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Solution {
  bool isroot(string &root, string &word)  //判断是否是词根的函数
  {
    for (int i = 0; i < root.size(); ++i)
      if (root[i] != word[i]) return false;
    return true;
  }

 public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    sort(dictionary.begin(), dictionary.end(),
         [](auto &s1, auto &s2) { return s1.size() < s2.size(); });
    string ans, word;
    stringstream input(sentence);
    while (input >> word) {
      for (auto &root : dictionary)
        if (isroot(root, word)) {
          word = root;
          break;
        }
      ans += word + " ";
    }
    ans.pop_back();
    return ans;
  }
};
// @lc code=end
