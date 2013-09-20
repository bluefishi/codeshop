//http://oj.leetcode.com/problems/reverse-linked-list-ii/
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
        ListNode* reverseBetween(ListNode* head, int m, int n)
        {
            if(m >= n)
              return head;
            int count = 0;
            ListNode* preStart = NULL;
            ListNode* start = NULL;
            ListNode* end = NULL;
            ListNode* pre = NULL;
            ListNode* cur = head;
            while(cur != NULL)
            {
                count += 1;
                if(m == count)
                {
                    preStart = pre;
                    start = cur;
                }
                else if(n == count)
                {
                    end = cur;
                    break;
                }
                pre = cur;
                cur = cur->next;
            }
            if(start == NULL || end == NULL)
              return head;
            cur = start;
            pre = end->next;
            ListNode* curEnd = end->next;
            ListNode* curNext = NULL;
            while(cur != curEnd)
            {
                curNext = cur->next;
                cur->next = pre;
                pre = cur;
                cur = curNext;
            }
            if(preStart != NULL)
            {
                preStart->next = end;
                return head;
            }
            else
            {
                return end;
            }
        }

};

