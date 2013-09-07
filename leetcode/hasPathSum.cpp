//http://leetcode.com/onlinejudge#question_112
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL) 
        {
            if(sum == root->val)
             return true;
            else
             return false;
        } 
        if(hasPathSum(root->left, sum - root->val))
          return true;
        if(hasPathSum(root->right, sum - root->val))
          return true;
        return false;
    }
};
