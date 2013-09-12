//http://leetcode.com/onlinejudge#question_129
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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
   
void sumNumbers(TreeNode* root, int curSum, int& sum)
{
    if(root == NULL)
        return ;
    if(root->left != NULL)
       sumNumbers(root->left, curSum*10 + root->val, sum);
    if(root->right != NULL)
       sumNumbers(root->right, curSum*10 + root->val, sum);
    if(root->left == NULL && root->right == NULL)
       sum += (curSum*10+root->val);
}

};
