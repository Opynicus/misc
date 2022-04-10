/*
 * @Author: Opynicus
 * @Date: 2022-03-28 17:15:15
 * @LastEditTime: 2022-03-28 17:18:11
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\226.翻转二叉树.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=226 lang=golang
 *
 * [226] 翻转二叉树
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
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil;
	}
	lchild := invertTree(root.Left)
	rchild := invertTree(root.Right)
	root.Left, root.Right = rchild, lchild
	return root
}
// @lc code=end

