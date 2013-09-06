//http://leetcode.com/onlinejudge#question_102
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(root == NULL)
          return ret;
        ret.push_back(vector<int>());
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            if(cur != NULL)
            {
                ret.back().push_back(cur->val);
                if(cur->left != NULL)
                  que.push(cur->left);
                if(cur->right != NULL)
                  que.push(cur->right);
            }
            else if(que.size() > 0)
            {
              ret.push_back(vector<int>());
              que.push(NULL);
            }
        }
        return ret;
    }
};

