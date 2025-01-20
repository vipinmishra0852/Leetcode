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
    string helper(TreeNode* root)
    {
        if(root == NULL) return "";
        if(root->left == NULL && root->right == NULL)
        {
         return (to_string(root->val)+ +"$");
        }
        return (helper(root->left)+helper(root->right));
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
    string sum1 = "";
    string sum2 = "";
    sum1 = helper(root1);
    sum2 = helper(root2);
    cout<<"sum1 : "<<sum1<<endl;
    cout<<"sum2 : "<<sum2<<endl;
    if(sum1 == sum2) return true;
    return false; 
    }
};