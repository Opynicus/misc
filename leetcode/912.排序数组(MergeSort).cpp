/*
 * @Author: Opynicus
 * @Date: 2022-04-06 13:47:20
 * @LastEditTime: 2022-04-06 14:02:02
 * @LastEditors: Opynicus
 * @Description: mergesort
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
    vector<int> tmp;
    void Merge(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++)
        {
            tmp[i] = nums[i];
        }
        int i, j, k;
        for (i = left, j = mid + 1, k = left; i <= mid && j <= right; k++)
        {
            if (tmp[i] <= tmp[j])
            {
                nums[k] = tmp[i];
                i++;
            }
            else
            {
                nums[k] = tmp[j];
                j++;
            }
        }
        while (i <= mid)
        {
            nums[k] = tmp[i];
            k++;
            i++;
        }
        while (j <= right)
        {
            nums[k] = tmp[j];
            k++;
            j++;
        }
        
    }
    void MergeSort(vector<int>& nums, int left, int right) {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            MergeSort(nums, left, mid);
            MergeSort(nums, mid+1, right);
            Merge(nums, left, mid, right);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

