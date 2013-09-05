//http://leetcode.com/onlinejudge#question_98
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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minv, maxv;
        return isValidBST(root, minv, maxv);
           
    }

    bool isValidBST(TreeNode *root, int& minv, int& maxv)
    {
        if(root == NULL)
          return true;
        minv = root->val;
        maxv = root->val;
        int lminv, lmaxv, rminv, rmaxv;
        if(root->left != NULL && isValidBST(root->left, lminv, lmaxv) == false)
          return false;
        if(root->right != NULL && isValidBST(root->right, rminv, rmaxv) == false)
          return false;
        if(root->left != NULL)
        {
            if(root->val <= lmaxv)
              return false;
            minv = lminv;
        }
        if(root->right != NULL)
        {
            if(root->val >= rminv)
              return false;
            maxv = rmaxv;
        }
        return true;
    }
};

