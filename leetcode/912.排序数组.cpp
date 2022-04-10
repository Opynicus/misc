/*
 * @Author: Opynicus
 * @Date: 2022-04-04 17:04:35
 * @LastEditTime: 2022-04-04 20:15:04
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
    int Partition(vector<int>& nums, int low, int high) {
        int i = rand() % (high - low + 1) + low;
        swap(nums[low], nums[i]);
        int pivot = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= pivot)
            {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot)
            {
                low++;
            }
            nums[high] = nums[low];
            
        }
        nums[low] = pivot;
        return low;   
    }
    void QuickSort(vector<int>& nums, int low, int high) {
        if (low < high)
        {
            int pivot = Partition(nums, low, high);
            QuickSort(nums, low, pivot-1);
            QuickSort(nums, pivot+1, high);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

