/*
 * @lc app=leetcode.cn id=235 lang=golang
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */
var ans *TreeNode
func Ischild(root, p, q *TreeNode) bool {
	if root == nil {
		return false
	}
	lson := Ischild(root.Left, p, q)
	rson := Ischild(root.Right, p, q)
	if lson && rson || ((root == p || root == q) && (lson || rson)) {
		ans = root 
	}
	return lson || rson || root ==p || root == q
}
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	Ischild(root,p,q)
	return ans
}
// @lc code=end

