//http://leetcode.com/onlinejudge#question_109
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            p = p->next;
            ++i;
        }
        return sortedListToBST(head, 0, i - 1);
    }

    TreeNode* sortedListToBST(ListNode*& head, int left, int right)
    {
        if(left > right)
          return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* leftNode = sortedListToBST(head, left, mid - 1);
        TreeNode* parent = new TreeNode(head->val);
        parent->left = leftNode;
        head = head->next;
        TreeNode* rightNode = sortedListToBST(head, mid + 1, right);
        parent->right = rightNode;
        return parent;
    }
};
