/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    void heapAdjust(vector<int>& nums, int len, int idx) {
        int lchild = idx * 2 + 1;
        int rchild = idx * 2 + 2;
        int maxIdx = idx;
        if (lchild < len && nums[maxIdx] < nums[lchild])
        {
            maxIdx = lchild;
        }
        if (rchild < len && nums[maxIdx] < nums[rchild])
        {
            maxIdx = rchild;
        }
        if (maxIdx != idx)
        {
            swap(nums[maxIdx], nums[idx]);
            heapAdjust(nums, len, maxIdx);
        }
        
    }
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2 - 1; i >= 0; i--)
        {
            heapAdjust(nums, len , i);
        }
        
    }
    void HeapSort(vector<int>& nums, int len) {
        buildMaxHeap(nums, len);
        for (int i = len - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapAdjust(nums, i, 0);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        HeapSort(nums, nums.size());
        return nums[nums.size()-k];
    }
};
// @lc code=end

