/*
 * @Author: Opynicus
 * @Date: 2022-04-02 20:10:22
 * @LastEditTime: 2022-04-02 20:59:45
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\207.课程表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    bool valid = true;
    void dfs(int i) {
        vis[i] = 1;
        for (auto & p : graph[i])
        {
            if (vis[p] == 0)
            {
                dfs(p);
                if (!valid)
                {
                    return ;
                }
            }
            else if (vis[p] == 1)
            {
                valid = false;
                return ;
            }

            
        }
        vis[i] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        vis.resize(numCourses);
        //构建类似邻接表
        for (auto &pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
// @lc code=end

