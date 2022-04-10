/*
 * @Author: Opynicus
 * @Date: 2022-04-05 10:28:20
 * @LastEditTime: 2022-04-05 17:37:40
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\912.排序数组.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    void heapAdjust(vector<int>& nums, int len, int idx) {
        int leftchild = idx * 2 + 1;//左孩子
        int rightchild = idx * 2 + 2;//右孩子
        int maxIdx = idx;
        if (leftchild < len && nums[maxIdx] < nums[leftchild])
        {
            maxIdx = leftchild;
        }
        if (rightchild < len && nums[maxIdx] < nums[rightchild])
        {
            maxIdx = rightchild;
        }
        if (maxIdx != idx)
        {
            swap(nums[idx], nums[maxIdx]);
            heapAdjust(nums, len, maxIdx);
        }
        
    }
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2 - 1; i >= 0; i--)
        {
            heapAdjust(nums, len, i);
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
    vector<int> sortArray(vector<int>& nums) {
        HeapSort(nums, nums.size());
        return nums;
    }
};
// @lc code=end

