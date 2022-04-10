/*
 * @Author: Opynicus
 * @Date: 2022-04-06 20:20:05
 * @LastEditTime: 2022-04-06 20:48:37
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\215.数组中的第k个最大元素.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[left], nums[i]);
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
            {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
            {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
        
    }
    void QuickSort(vector<int>& nums, int left, int right) {
        if (left < right)
        {
            int pivot = partition(nums, left, right);
            QuickSort(nums, left, pivot);
            QuickSort(nums, pivot+1, right);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned)time(NULL));
        QuickSort(nums, 0 ,nums.size() - 1);
        return nums[nums.size()-k];
    }
};
// @lc code=end

