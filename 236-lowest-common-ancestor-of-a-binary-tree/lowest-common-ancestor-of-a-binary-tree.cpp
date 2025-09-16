/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* node,vector<TreeNode*>&vec)
    {
        if(root == NULL) return false;
        vec.push_back(root);
        if(root == node) return true;
        if( (getPath(root->left,node,vec)) || (getPath(root->right,node,vec)) ) return true;
        vec.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
    vector<TreeNode*>pvec;
    vector<TreeNode*>qvec;
    getPath(root,p,pvec);
    getPath(root,q,qvec); 
    int i = 0 ;
    TreeNode* lca = NULL;
    while( i < pvec.size() && i < qvec.size() && pvec[i] == qvec[i] )   
    {
     lca = pvec[i];
     i++;
    }
    return lca;
    }
};