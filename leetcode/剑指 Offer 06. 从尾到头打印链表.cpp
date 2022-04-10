// @algorithm @lc id=100282 lang=cpp 
// @title cong-wei-dao-tou-da-yin-lian-biao-lcof
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
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> ans;
        while (head)
        {
            stk.push(head->val);
            head = head->next;
        }
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};