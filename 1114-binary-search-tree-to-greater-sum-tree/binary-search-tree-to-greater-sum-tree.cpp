
class Solution {
public:
int sum=0;
    void inorder(TreeNode* root)
    {
    if(root==NULL) return;
     inorder(root->right);
     root->val=sum+root->val;
     sum=root->val;
    inorder(root->left);
    }

   


    TreeNode* bstToGst(TreeNode* root) {
    if(root==NULL) return NULL;
    inorder(root);
    return root;
    }
};