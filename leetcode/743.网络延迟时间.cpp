/*
 * @Author: Opynicus
 * @Date: 2022-03-31 19:50:51
 * @LastEditTime: 2022-03-31 21:16:24
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\743.网络延迟时间.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<long long>> graph(n + 1, vector<long long>(n + 1, INT_MAX));
        for(int i = 1; i <= n; i ++) {
            graph[i][i] = 0;
        }
        for(auto& t : times) {
            graph[t[0]][t[1]] = t[2];
        }
        for(int k = 1; k <= n; k ++) {
            for(int i = 1; i <= n; i ++) {
                for(int j = 1;j <= n; j ++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] +graph[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(graph[k][i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, (int)graph[k][i]);
        }
        return ans;
    }
};
// @lc code=end

