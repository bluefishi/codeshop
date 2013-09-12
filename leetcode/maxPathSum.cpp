//http://leetcode.com/onlinejudge#question_124
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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = 0x80000000; 
        maxPathSum(root, maxSum);
        return maxSum;
    }

    int maxPathSum(TreeNode* root, int& maxSum)
    {
        if(root == NULL)
          return -1;
        int leftMax = maxPathSum(root->left, maxSum);
        int rightMax = maxPathSum(root->right, maxSum);
        int curMaxSum;
        if(leftMax > 0 && rightMax > 0)
            curMaxSum = root->val + leftMax + rightMax;
        else if(leftMax > 0)
          curMaxSum = root->val + leftMax;
        else if(rightMax > 0)
          curMaxSum = root->val + rightMax;
        else
          curMaxSum = root->val;
        if(curMaxSum > maxSum)
          maxSum = curMaxSum;
        if(leftMax > 0 || rightMax > 0)
        {
          if(leftMax > rightMax)
            return root->val + leftMax;
          else
            return root->val + rightMax;
        }
        return root->val;
    }
};
