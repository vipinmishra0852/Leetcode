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
    vector<vector<int>>result;

    void helper(TreeNode* root,int target,int sum,vector<int>temp)
    {
        if(root == NULL) return;
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == target)
        {
            result.push_back(temp);
            return;
        }
        helper(root->left,target,sum,temp);
        helper(root->right,target,sum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
    int sum = 0;
    vector<int>temp;
    helper(root,targetSum,sum,temp);    
    return result;
    }
};