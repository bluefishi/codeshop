//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        ListNode* newHead = NULL;
        ListNode* last = NULL;
        ListNode* cur = head;
        while(cur != NULL)
        {
            int count = 0;
            ListNode* curBackup = cur;
            while(cur != NULL && cur->val == curBackup->val)
            {
                ++count;
                cur = cur->next;
            }
            if(count == 1)
            {
                if(newHead == NULL)
                {
                    newHead = curBackup;
                    last = newHead;
                }
                else
                {
                    last->next = curBackup;
                    last = last->next;
                }
            }
        }
        if(last != NULL)
          last->next = NULL;
        return newHead;
    }
};

