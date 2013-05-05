//http://leetcode.com/onlinejudge#question_2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//出现了三个错误才改正确
//1 l1 = l1->next; l2 = l2->next;忘记了
//2 ListNode* left; 忘记初始化left = NULL;导致while(left != NULL) runtime error
//3 忘记最后有可能有一个addition，也应该给新建一个node
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL && l2 == NULL)
            return NULL;
        int addition = 0;
        ListNode* head = NULL;
        ListNode* q = NULL;
        ListNode* p = head;
        int curVal = 0;
        while(l1 != NULL && l2 != NULL)
        {
            if(q == NULL)
            {
                head = new ListNode(-1);
                p = head;
            }
            else
            {
                p = new ListNode(-1);
                q->next = p;
            }
            curVal = l1->val + l2->val + addition;
            p->val = curVal % 10;
            addition = curVal / 10;
            q = p;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* left = NULL;
        if(l1 != NULL)
            left = l1;
        if(l2 != NULL)
            left = l2;
        while(left != NULL)
        {
            p = new ListNode(-1);
            curVal = left->val + addition;
            p->val = curVal % 10;
            addition = curVal / 10;
            q->next = p; 
            q = p;
            left = left->next;
        }
        if(addition != 0)
    	{
			p = new ListNode(addition);
			q->next = p;
		}
        return head;
    }
};

