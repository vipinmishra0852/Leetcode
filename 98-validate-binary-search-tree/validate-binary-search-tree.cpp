class Solution {
public:
   void inorder(TreeNode* root,vector<int>&ans)
   {
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
    return;
   }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i-1]>=ans[i]) return false;
        }
        return true;
    }
};
