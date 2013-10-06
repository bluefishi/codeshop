//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* last = head;
        ListNode* cur = head;
        while(cur != NULL)
        {
            while(cur != NULL && cur->val == last->val)
              cur = cur->next;
            last->next = cur;
            last = last->next;
        }
        return head;
    }
};

