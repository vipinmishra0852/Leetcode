
class Solution {
public:
    void insertIntoBST(TreeNode* root,int value)
    {
      if(root==NULL)  root=new TreeNode(value);
      if(root->val > value) 
      {
      if(root->left==NULL) 
      {
        root->left=new TreeNode(value);
      }
      else insertIntoBST(root->left,value);
      }
      else
      { if(root->right==NULL) 
      {
        root->right=new TreeNode(value);
      }
      else insertIntoBST(root->right,value);

    }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) 
    {
     int n=pre.size();
     TreeNode* root=new TreeNode(pre[0]);
     for(int i=1;i<n;i++)
     {
       insertIntoBST(root,pre[i]);
     }
     return root;
    }
};