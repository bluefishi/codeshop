//http://oj.leetcode.com/problems/partition-list/
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
        ListNode* partition(ListNode* head, int x)
        {
            ListNode* lessHead = NULL;
            ListNode* moreHead = NULL;
            ListNode* lessCur = NULL;
            ListNode* moreCur = NULL;
            ListNode* cur = head;
            while(cur != NULL)
            {
                if(cur->val < x)
                {
                    if(lessHead == NULL)
                    {
                        lessHead = cur;
                        lessCur = lessHead;
                    }
                    else
                    {
                        lessCur->next = cur;
                        lessCur = lessCur->next;
                    }
                }
                else
                {
                    if(moreHead == NULL)
                    {
                        moreHead = cur;
                        moreCur = moreHead;
                    }
                    else
                    {
                        moreCur->next = cur;
                        moreCur = moreCur->next;
                    }
                }
                cur = cur->next;
            }
            if(lessHead == NULL && moreHead == NULL)
            {
                return NULL;
            }
            else if(lessHead == NULL && moreHead != NULL)
            {
                return moreHead;
            }
            else if(lessHead != NULL && moreHead == NULL)
            {
                return lessHead;
            }
            else
            {
                lessCur->next = moreHead;
                moreCur->next = NULL;
                return lessHead;
            }
        }

};

