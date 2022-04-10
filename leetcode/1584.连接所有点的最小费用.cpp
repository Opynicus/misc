/*
 * @Author: Opynicus
 * @Date: 2022-03-30 21:00:37
 * @LastEditTime: 2022-03-30 21:24:33
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\1584.连接所有点的最小费用.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class Solution {
public:
    int distance( vector<int>& A, vector<int>& B){
        return abs(A[0]-B[0]) + abs(A[1]-B[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<bool> vis(N, false);
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        int ans = 0;
        for(int u = 0; u < N; u++) {
            //1，从边集中，选出权重最小的边，
            int v = -1;
            int v_dist = INT_MAX;
            for(int i = 0;i < N;i++) {
                if(!vis[i] && dist[i] < v_dist){
                    v = i;
                    v_dist = dist[i];
                }
            }
            //2，将v加入最小生成树。
            vis[v] = true;
            ans += v_dist;
            //3，更新边集。新顶点加入边集，更新到其它点的距离
            for(int i = 0; i < N; i++){
                if(!vis[i]){
                    int d = distance(points[i], points[v]);
                    dist[i] = min(dist[i], d);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

