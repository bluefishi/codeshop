//http://leetcode.com/onlinejudge#question_99
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<TreeNode*> swapNodes;
        deque<TreeNode*> tranverseTwo;
        tranverseTree(root, tranverseTwo, swapNodes);
        if(swapNodes.size() != 2)
          return;
        TreeNode* sn1 = swapNodes.front();
        TreeNode* sn2 = swapNodes.back();
		int tmp = sn1->val;
		sn1->val = sn2->val;
		sn2->val = tmp;
    }

    void tranverseTree(TreeNode* root, deque<TreeNode*>& tranverseTwo, deque<TreeNode*>& swapNodes)
    {
        if(root == NULL)
          return;
        tranverseTree(root->left, tranverseTwo, swapNodes);
        if(tranverseTwo.size() < 1)
        {
            tranverseTwo.push_back(root); 
        }
        else
        {
            tranverseTwo.push_back(root);
            if(swapNodes.size() == 0)
            {
                if(tranverseTwo.front()->val > tranverseTwo.back()->val)
                {
                    swapNodes.push_back(tranverseTwo.front());
                    swapNodes.push_back(tranverseTwo.back());
                }
            }
            else
            {
                if(tranverseTwo.front()->val > tranverseTwo.back()->val)
                    swapNodes.back() = tranverseTwo.back();
            }
            tranverseTwo.pop_front();
        }
        tranverseTree(root->right, tranverseTwo, swapNodes);
    }
};
