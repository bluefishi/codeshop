//http://oj.leetcode.com/problems/unique-binary-search-trees-ii/
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
        vector<TreeNode*> generateTrees(int n)
        {
            vector<TreeNode*> roots = generateTreesInternal(n);
            int val = 0;
            for(int i = 0; i < roots.size(); ++i)
            {
                val = 1;
            	InsertValue(roots[i], val);
            }
            return roots;
        }

        void InsertValue(TreeNode* root, int& val)
        {
            if(root == NULL)
              return;
            InsertValue(root->left, val);
            root->val = val++;
            InsertValue(root->right, val);
        }

        void ReleaseTree(TreeNode* root)
        {
            if(root == NULL)
              return;
            ReleaseTree(root->left);
            ReleaseTree(root->right);
            delete root;
            root = NULL;
        }

        TreeNode* CopyTree(TreeNode* root)
        {
            if(root == NULL)
              return NULL;
            TreeNode* newRoot = new TreeNode(root->val);
            newRoot->left = CopyTree(root->left);
            newRoot->right = CopyTree(root->right);
            return newRoot;
        }
        vector<TreeNode*> generateTreesInternal(int n)
        {
            vector<TreeNode*> ret;
            if(n == 0)
            {
                ret.push_back(NULL);
                return ret;
            }
            if(n == 1)
            {
                ret.push_back(new TreeNode(1));
                return ret;
            }
            for(int i = 0; i <= n - 1; ++i)
            {
                vector<TreeNode*> leftRoot = generateTreesInternal(i);
                vector<TreeNode*> rightRoot = generateTreesInternal(n-1-i);
                for(int i = 0; i < leftRoot.size(); ++i)
                {
                    for(int j = 0; j < rightRoot.size(); ++j)
                    {
                        TreeNode* root = new TreeNode(i+1);
                        root->left = CopyTree(leftRoot[i]);
                        root->right = CopyTree(rightRoot[j]);
                        ret.push_back(root);
                    }
                }
                for(int i = 0; i < leftRoot.size(); ++i)
                {
                    ReleaseTree(leftRoot[i]);
                }
                for(int i = 0; i < rightRoot.size(); ++i)
                {
                    ReleaseTree(rightRoot[i]);
                }
            }
            return ret;
        } 

};
