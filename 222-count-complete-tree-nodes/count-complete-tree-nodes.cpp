
class Solution {
public:
    void helper(TreeNode* root,int &count)
    {
        if(root == NULL ) return ;
        
        helper(root->left,count);
        helper(root->right,count);
        count = count + 1;
        
    }
    int countNodes(TreeNode* root) 
    {
    if(root == NULL) return 0;
    int count = 0;
    helper(root,count); 
    return count; 
    }
};