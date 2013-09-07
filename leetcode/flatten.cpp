//http://leetcode.com/onlinejudge#question_114
//注意需要把left全部置为NULL
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* pre = NULL;
        Preorder(root, pre); 
        while(root != NULL)
        {
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }

    void Preorder(TreeNode* root, TreeNode*& pre)
    {
        if(root == NULL)
          return;
        if(pre != NULL)
          pre->left = root;
        pre = root;
        Preorder(root->left, pre);
        Preorder(root->right, pre);
    }
};
