//http://leetcode.com/onlinejudge#question_61
//note: if k > len(list), take it as a cycle list
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
        ListNode *rotateRight(ListNode *head, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(head == NULL || k == 0)
              return head;
            int i = 0;
            ListNode* fast = head;
            ListNode* pfast = NULL;
            while(i < k)
            {
                if(fast == NULL)
                  fast = head;
                pfast = fast;
                fast = fast->next;
                i += 1;

            }	
            ListNode* pslow = NULL;
            ListNode* slow = head;
            while(fast != NULL)
            {
                pfast = fast;
                fast = fast->next;
                pslow = slow;
                slow = slow->next;
            }
            if(pslow != NULL)
            {
                if(pfast != NULL)
                  pfast->next = head;
                pslow->next = NULL;
            }
            return slow;
        }
};

