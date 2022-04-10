/*
 * @Author: Opynicus
 * @Date: 2022-04-09 09:42:32
 * @LastEditTime: 2022-04-09 09:44:54
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinedf:\github_repos\leetcode\cn\C++\question\___Offer_52_______________LCOF.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
// @algorithm @lc id=100326 lang=cpp 
// @title liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> vis;
        ListNode* tmp = headA;
        while (tmp)
        {
            vis.insert(tmp);
            tmp = tmp ->next;
        }
        tmp = headB;
        while (tmp)
        {
            if (vis.count(tmp))
            {
                return tmp;
            }
            tmp = tmp->next;
        }
        return NULL;
        
    }
};