//http://leetcode.com/onlinejudge#question_107
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
          return vector<vector<int> >();
        int height = Height(root);
        vector<vector<int> > ret(height); 
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        for(int i = 0; i < height; ++i)
        {
            while(que.front() != NULL)
            {
                TreeNode* cur = que.front();
                ret[height - i - 1].push_back(cur->val);
                if(cur->left != NULL)
                  que.push(cur->left);
                if(cur->right != NULL)
                  que.push(cur->right);
                que.pop();
            }
            que.pop();
            que.push(NULL);
        }
        return ret;
    }

    int Height(TreeNode* root)
    {
        if(root == NULL)
          return 0;
        return max(Height(root->left), Height(root->right)) + 1;
    }

};
