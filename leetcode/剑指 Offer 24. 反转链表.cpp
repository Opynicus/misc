/*
 * @Author: Opynicus
 * @Date: 2022-04-08 20:50:59
 * @LastEditTime: 2022-04-08 21:00:46
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinedf:\github_repos\leetcode\cn\C++\question\___Offer_24______LCOF.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
// @algorithm @lc id=100298 lang=cpp 
// @title fan-zhuan-lian-biao-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
        {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        head->next = NULL;
        while (cur)
        {
            ListNode* Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }
        return prev;
        
    }
};