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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder, 0, postorder, 0, inorder.size());
        
    }

    TreeNode* buildTree(vector<int>& inorder, int iIndex, vector<int>& postorder, int pIndex, int size)
    {
        if(size <= 0)
          return NULL;
        int mIndex = iIndex;
        TreeNode* root = new TreeNode(postorder[pIndex+size-1]);
        for(int i = 0; i < size; ++i)
        {
            if(inorder[i + iIndex] == root->val)
            {
              mIndex = i + iIndex;
              break;
            }
        }
        root->left = buildTree(inorder, iIndex, postorder, pIndex, mIndex - iIndex);
        root->right = buildTree(inorder, mIndex + 1, postorder, pIndex + mIndex - iIndex, size - mIndex + iIndex - 1);
        return root;
    }
};

