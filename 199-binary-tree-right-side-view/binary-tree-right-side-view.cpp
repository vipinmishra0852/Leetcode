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
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left=levels(root->left);
        int right= levels(root->right);
        return 1+max(left,right);
    }
    void nthLevel(TreeNode* root , int curr, int level,vector<int>&ans)
    {
        if(root==NULL) return;
        if(curr==level)
        {
            ans[curr]=root->val;
        }
        nthLevel(root->left,curr+1,level,ans);
         nthLevel(root->right,curr+1,level,ans);
    }
    void levelOrder(TreeNode* root,vector<int>&ans)
    {
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            nthLevel(root,0,i,ans);
        }

    }
    vector<int> rightSideView(TreeNode* root) 
    {
     vector<int>ans(levels(root),0);
     levelOrder(root,ans);
     return ans;   
    }
};