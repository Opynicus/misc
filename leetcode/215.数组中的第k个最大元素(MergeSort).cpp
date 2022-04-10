/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    vector<int> tmp;
    void Merge(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right ; i++)
        {
            tmp[i] = nums[i];
        }
        int i,j,k;
        for (i = left, j = mid+1, k = left; i <= mid && j <= right; k++)
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
    int findKthLargest(vector<int>& nums, int k) {
        tmp.resize(nums.size(), 0);
        MergeSort(nums, 0, nums.size() - 1);
        return nums[nums.size()-k];
    }
};
// @lc code=end

