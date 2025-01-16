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
    TreeNode* helper(TreeNode* root,set<int>st,vector<TreeNode*>&v)
    {
        if(root == NULL) return NULL;
        root->left = helper(root->left,st,v);
        root->right = helper(root->right,st,v);
        if(st.find(root->val) != st.end() )
        {
            if(root->left != NULL)
            {
                v.push_back(root->left);
            }
            if(root->right != NULL)
            {
                v.push_back(root->right);
            }
            return NULL;
        }
        else
        {
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
    vector<TreeNode*>v;
    set<int>st;
    for(auto it:to_delete)
    {
        st.insert(it);
    }
    helper(root,st,v);
    if(st.find(root -> val) == st.end())
    {
        v.push_back(root);
    }
    return v;

    

    }
};