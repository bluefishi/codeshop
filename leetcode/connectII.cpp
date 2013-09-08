//http://leetcode.com/onlinejudge#question_74
//本质是BFS
//TreeLinkNode中next域可以先把上层连起来，实际上等于BFS中的队列
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(root != NULL)
        {
            TreeLinkNode* head = NULL;
            while(root != NULL)
            {
                if(root->left != NULL || root->right != NULL)
                  break;
                root = root->next;
            }
            if(root == NULL)
              break;
            TreeLinkNode* curParent = root;
            TreeLinkNode* curLink = NULL;
            while(curParent != NULL)
            {
                if(curParent->left != NULL)
                {
                    if(head == NULL)
                    {
                        head = curParent->left;
                        curLink = head;
                    }
                    else
                    {
                        curLink->next = curParent->left;
                        curLink = curLink->next;
                    }
                }
                if(curParent->right != NULL)
                {
                    if(head == NULL)
                    {
                        head = curParent->right;
                        curLink = head;
                    }
                    else
                    {
                        curLink->next = curParent->right;
                        curLink = curLink->next;
                    }
                }
                curParent = curParent->next;
            }
            root = head;
        }
    }
};
