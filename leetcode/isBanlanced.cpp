//http://leetcode.com/onlinejudge#question_110
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rh;
        return isBalanced(root, rh);
    }

    bool isBalanced(TreeNode* root, int& height)
    {
        if(root == NULL)
        {
            height = 0;
            return true;
        }
        int lh, rh;
        if(isBalanced(root->left, lh) == false)
          return false;
        if(isBalanced(root->right, rh) == false)
          return false;
        height = max(lh, rh) + 1;
        if(abs(lh - rh) <= 1)
          return true;
        return false;
    }
};
