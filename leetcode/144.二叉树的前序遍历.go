/*
 * @Author: Opynicus
 * @Date: 2022-01-13 15:26:33
 * @LastEditTime: 2022-01-13 15:48:46
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\144.二叉树的前序遍历.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=144 lang=golang
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func preorderTraversal(root *TreeNode) (res []int) {
    var traversal func(node *TreeNode)
    traversal = func(node *TreeNode) {
	if node == nil {
            return
	}
	res = append(res,node.Val)
	traversal(node.Left)
	traversal(node.Right)
    }
    traversal(root)
    return res
}
// @lc code=end

