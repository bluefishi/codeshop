//not passed
//run time error
//http://leetcode.com/onlinejudge#question_99
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<TreeNode*> swapNodes;
        deque<TreeNode*> swapNodesParent;
        deque<TreeNode*> tranverseTwo;
        deque<TreeNode*> tranverseTwoParent;
        tranverseTree(root, NULL, tranverseTwo, tranverseTwoParent, swapNodes, swapNodesParent);
        if(swapNodes.size() != 2)
          return;
        TreeNode* sn1 = swapNodes.front();
        TreeNode* sn2 = swapNodes.back();
        TreeNode* sn1Parent = swapNodesParent.front();
        TreeNode* sn2Parent = swapNodesParent.back();
        TreeNode* sn1Left = sn1->left;
        TreeNode* sn1Right = sn1->right;
        TreeNode* sn2Left = sn2->left;
        TreeNode* sn2Right = sn2->right;
        if(sn1->left == sn2 || sn1->right == sn2)
        {
            if(sn1Parent != NULL)
            { 
              if(sn1Parent->left == sn1)
                sn1Parent->left = sn2;
              else
                sn1Parent->right = sn2;
            }
            sn1->left = sn2Left;
            sn1->right = sn2Right;
            if(sn1->left == sn2)
              sn2->left = sn1;
            else
              sn2->right = sn1;
            return;
        }
        if(sn2->left == sn1 || sn2->right == sn1)
        {
            if(sn2Parent != NULL)
            {
                if(sn2Parent->left == sn2)
                  sn2Parent->left = sn1;
                else
                  sn2Parent->right = sn1;
            }
            sn2->left = sn1Left;
            sn2->right = sn1Right;
            if(sn2->left == sn1)
              sn1->left = sn2;
            else
              sn1->right = sn2;
            return;
        }
        sn1->left = sn2Left;
        sn1->right = sn2Right;
        sn2->left = sn1Left;
        sn2->right = sn1Right;
        if(sn1Parent != NULL)
        {
            if(sn1Parent->left == sn1)
              sn1Parent->left = sn2;
            else
              sn1Parent->right = sn2;
        }
        if(sn2Parent != NULL)
        {
            if(sn2Parent->left == sn2)
              sn2Parent->left = sn1;
            else
              sn2Parent->right = sn1;
        }
    }

    void tranverseTree(TreeNode* root, TreeNode* parent, deque<TreeNode*>& tranverseTwo, deque<TreeNode*>& tranverseTwoParent
                ,deque<TreeNode*>& swapNodes, deque<TreeNode*>& swapNodesParent)
    {
        if(root == NULL)
          return;
        tranverseTree(root->left, root, tranverseTwo, tranverseTwoParent, swapNodes, swapNodesParent);
        if(tranverseTwo.size() < 1)
        {
            tranverseTwo.push_back(root); 
            tranverseTwoParent.push_back(parent);
        }
        else
        {
            tranverseTwo.push_back(root);
            tranverseTwoParent.push_back(parent);
            if(swapNodes.size() == 0)
            {
                if(tranverseTwo.front()->val > tranverseTwo.back()->val)
                {
                    swapNodes.push_back(tranverseTwo.front());
                    swapNodesParent.push_back(tranverseTwoParent.front());
                    swapNodes.push_back(tranverseTwo.back());
                    swapNodesParent.push_back(tranverseTwoParent.back());
                }
            }
            else
            {
                if(tranverseTwo.front()->val > tranverseTwo.back()->val)
                {
                    swapNodes.back() = tranverseTwo.back();
                    swapNodesParent.back() = tranverseTwoParent.back();
                }
            }
            tranverseTwo.pop_front();
            tranverseTwoParent.pop_front();
        }
        tranverseTree(root->right, root, tranverseTwo, tranverseTwoParent, swapNodes, swapNodesParent);
    }
};
