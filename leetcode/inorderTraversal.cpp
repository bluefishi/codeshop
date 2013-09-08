//http://leetcode.com/onlinejudge#question_94
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        Preorder(root, ret);
        return ret;
    }

    void Preorder(TreeNode* root, vector<int>& ret)
    {
        if(root == NULL)
          return;
        Preorder(root->left, ret);
        ret.push_back(root->val);
        Preorder(root->right, ret);
    }
};
