//http://leetcode.com/onlinejudge#question_21
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
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(l1 == NULL && l2 == NULL)
              return NULL;
            if(l1 == NULL)
              return l2;
            if(l2 == NULL)
              return l1;
            ListNode* h;
            if(l1->val < l2->val)
            {
                h = l1;
                l1 = l1->next;
            }
            else
            {
                h = l2;
                l2 = l2->next;
            }
            ListNode* p = h;
            while(l1 != NULL && l2 != NULL)
            {
                if(l1->val < l2->val)
                {
                    p->next = l1;
                    l1 = l1->next;
                    p = p->next;
                }
                else
                {
                    p->next = l2;
                    l2 = l2->next;
                    p = p->next;
                }
            }
            if(l1 != NULL)
              p->next = l1;
            else
              p->next = l2;
            return h;
        }
};

