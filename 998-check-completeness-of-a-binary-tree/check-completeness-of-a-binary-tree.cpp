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
    bool solve(TreeNode* root,int &idx,int &nodes)
    {
        if(root == NULL) return true;
        if(idx >= nodes) return false;
       
        int i = 2*idx + 1;
        int j = 2*idx + 2;
        return (solve(root->left,i,nodes) && solve(root->right,j,nodes));
    }
    int countnodes(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + countnodes(root->left) + countnodes(root->right);
    }
    bool isCompleteTree(TreeNode* root) 
    {
     int nodes = countnodes(root); 
     int i = 0;
     bool ans = solve(root,i,nodes);
     return ans;  
    }
};