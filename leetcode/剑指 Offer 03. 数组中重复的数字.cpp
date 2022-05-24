// @algorithm @lc id=100275 lang=cpp 
// @title shu-zu-zhong-zhong-fu-de-shu-zi-lcof


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
       unordered_map<int, int> kv;
       for (auto &i : nums)
       {
           if (kv.find(i) == kv.end())
           {
               kv.emplace(i, 1);
           } else {
               kv.at(i)++;
           }
           
       }
       for (auto i = kv.begin(); i != kv.end(); i++)
       {
           if (i->second > 1)
           {
               return i->first;
           }
           
       }
       return -1;
    }
};