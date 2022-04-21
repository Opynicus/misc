/*
 * @Author: Opynicus
 * @Date: 2022-04-20 16:02:49
 * @LastEditTime: 2022-04-20 16:14:30
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinedf:\github_repos\Leetcode_Solutions\96.不同的二叉搜索树.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) { //i插入右边
            for (int j = 1; j <= i; j++) {//j插入左边
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
// @lc code=end

