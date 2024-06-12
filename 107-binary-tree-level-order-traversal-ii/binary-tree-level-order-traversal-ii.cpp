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
int levels(TreeNode* root)
{
  if (root == NULL)
    return 0;
  return 1 + max(levels(root->left), levels(root->right));
}
void displayNthLevel(TreeNode *a, int curr, int l,vector<int>&v)
{
  if (a == NULL)
    return;
  if (curr == l)
  {
    v.push_back(a->val);
    
  }
  displayNthLevel(a->left, curr + 1, l,v);
  displayNthLevel(a->right, curr + 1, l,v);

}
void levelorder(TreeNode *a,vector<vector<int>>&ans)
{
  int n = levels(a);
  for (int i = n; i >= 1; i--)
  { 
    vector<int>v;
    displayNthLevel(a, 1, i,v);
    ans.push_back(v);
  }
}

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
    vector<vector<int>>ans;
    levelorder(root,ans);
    return ans;
  
    }
};