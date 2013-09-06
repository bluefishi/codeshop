//http://leetcode.com/onlinejudge#question_101
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(root == NULL)
         return true;
       return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
          return true;
        if(root1 == NULL || root2 == NULL)
          return false;
        if(root1->val != root2->val)
          return false;
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};

