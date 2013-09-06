//http://leetcode.com/onlinejudge#question_103
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(root == NULL)
          return ret;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        ret.push_back(vector<int>());
        bool left = true;
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
            else 
            {
                if(!left)
                  reverse(ret.back().begin(), ret.back().end());
                left = !left;
                if(que.size() > 0)
                {
                    ret.push_back(vector<int>());
                    que.push(NULL);
                }
            }
        }
        
    }
};

