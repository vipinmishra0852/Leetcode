/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans=false;
    void helper(TreeNode* root, int targetSum) 
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) 
        {
            if(root->val-targetSum==0)
            {
                ans=true;
                
            }
            return ;
        }
        helper(root->left,targetSum-(root->val));
        helper(root->right,targetSum-(root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==NULL) return false;
       helper(root,targetSum);
       return ans;
    }
};