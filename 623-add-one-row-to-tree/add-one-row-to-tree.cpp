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
    TreeNode* add(TreeNode* root,int val,int depth,int curr)
    {
        if(root == NULL) return NULL;
        if(depth - 1 == curr)
        {
            TreeNode* templeft = new TreeNode(val);
            TreeNode* tempright = new TreeNode(val);

            templeft->left = root->left;
            tempright->right = root->right;
            root->left = templeft;
            root->right = tempright;
           
            return root;
        }
       root->left =  add(root->left,val,depth,curr+1);
       root->right = add(root->right,val,depth,curr+1);
       return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
    if(root == NULL) return NULL;
    if(depth == 1)
    {
        TreeNode* temp = new TreeNode(val);
        temp->left = root;
        return temp;
    }    
    int curr = 1;
    return add(root,val,depth,curr);
    }
};