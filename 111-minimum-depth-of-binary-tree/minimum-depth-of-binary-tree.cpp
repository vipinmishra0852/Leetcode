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
    int helper(TreeNode* root,int l)
    {
         if(root==NULL) return INT_MAX;
         if(root->left==NULL && root->right==NULL) return l;
         if(root->left==NULL || root->right==NULL) 
         {
         int left = helper( root->left,l+1);
         int right =  helper(root->right,l+1); 
         return min(left,right);
         }
         int left = helper( root->left,l+1);
         int right =  helper(root->right,l+1);
         return min(left,right);
    }
    int minDepth(TreeNode* root)
    {
      if(root==NULL) return 0;
      int ans=helper(root,1);
      return ans;
    }
};