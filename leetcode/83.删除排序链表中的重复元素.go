/*
 * @Author: Opynicus
 * @Date: 2022-01-11 13:35:30
 * @LastEditTime: 2022-01-11 13:40:04
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\83.删除排序链表中的重复元素.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=83 lang=golang
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	cur := head
	for cur.Next != nil {
		if cur.Val == cur.Next.Val {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}
	return head
}
// @lc code=end

