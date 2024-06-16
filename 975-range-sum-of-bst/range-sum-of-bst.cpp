
class Solution {
public:
void inorder(TreeNode* root,vector<int>&v)
{
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
       vector<int>ans;
       inorder(root,ans); 
       int sum=0;
       for(int i=0;i<ans.size();i++)
       {
        if(ans[i]>=low && ans[i]<=high)
        {
        sum=sum+ans[i];
        }
       }
       return sum;
    }
};