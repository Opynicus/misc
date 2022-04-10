/*
 * @Author: Opynicus
 * @Date: 2022-04-01 19:12:44
 * @LastEditTime: 2022-04-01 19:42:43
 * @LastEditors: Opynicus
 * @Description: dfs+ AOV
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        stack<int> indegree0;
        int num = numCourses;
        for (auto & pre : prerequisites)
        {
            indegree[pre[0]]++;
            graph[pre[1]].push_back(pre[0]);
        }
        // for(int i=0;i<prerequisites.size();i++)
        // {
        //     indegree[prerequisites[i][0]]++;
        //     graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        // }
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                indegree0.push(i);
                num--;
            }
            
        }
        while (!indegree0.empty())
        {
            int tmp = indegree0.top();
            indegree0.pop();
            for (int i = 0; i < graph[tmp].size(); i++)
            {
                indegree[graph[tmp][i]]--;
                if (indegree[graph[tmp][i]] == 0)
                {
                    indegree0.push(graph[tmp][i]);
                    num--;
                }
                
            }
            
        }
        if (num == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
// @lc code=end

