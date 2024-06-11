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
    void helper(TreeNode* root, vector<string>&ans,string s )
    {   if(root==NULL) return ;
        if(root->left == NULL && root->right == NULL)
        {
         s = s + to_string(root -> val);
         ans.push_back(s);
         return;
        }
        string a = to_string(root->val);
        helper(root->left,ans,s+a+"->");
        helper(root->right,ans,s+a+"->");

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        helper(root,ans,"");
        return ans;
    }
};