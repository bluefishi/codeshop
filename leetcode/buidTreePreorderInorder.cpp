//http://leetcode.com/onlinejudge#question_105
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, int pIndex, vector<int>& inorder, int iIndex, int size)
    {
        if(size <= 0)
          return NULL;
        TreeNode* root = new TreeNode(preorder[pIndex]);
        int mIndex = iIndex;
        for(int i = 0; i < size; ++i)
        {
            if(inorder[iIndex + i] == root->val)
            {
              mIndex = iIndex + i;
              break;
            }
        }
        root->left = buildTree(preorder, pIndex + 1, inorder, iIndex, mIndex - iIndex);
        root->right = buildTree(preorder, pIndex + mIndex - iIndex + 1, inorder, mIndex + 1, size - mIndex + iIndex - 1);
        return root;
    }
};

