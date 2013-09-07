//http://leetcode.com/onlinejudge#question_113
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> path;
        pathSum(root, sum, path, ret);
        return ret;
    }

    void pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int> >& ret)
    {
        if(root == NULL)
          return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == sum)
            {
                path.push_back(root->val);
                ret.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        pathSum(root->left, sum - root->val, path, ret);
        pathSum(root->right, sum - root->val, path, ret);
        path.pop_back();
    }
};
