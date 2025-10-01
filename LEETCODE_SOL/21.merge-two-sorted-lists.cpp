/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c;
        ListNode* head = c;
        ListNode* tmp = list1;
        do{
            c->val = tmp->val;
            c = c->next;
        }while (tmp->next != nullptr);

        tmp = list2;

        while (tmp->next != nullptr)
        {
            c->val = tmp->val;
            c = c->next;
        }
        
        c->val = tmp->val;
        c->next = nullptr;

        return head;
    }
};
// @lc code=end

