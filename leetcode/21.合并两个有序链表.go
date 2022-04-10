/*
 * @Author: your name
 * @Date: 2022-01-07 12:59:25
 * @LastEditTime: 2022-01-07 14:19:00
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \COP2000e:\leetcode\21.合并两个有序链表.go
 */
/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	} else if list1.Val < list2.Val {
		list1.Next = mergeTwoLists(list1.Next, list2);
		return list1;
	} else {
		list2.Next = mergeTwoLists(list1, list2.Next);
		return list2;
	}
}
// @lc code=end

