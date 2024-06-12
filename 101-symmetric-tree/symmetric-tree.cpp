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
    bool check(TreeNode* p , TreeNode* q)
    {
    if(p==NULL && q==NULL ) return true;
    else if(p==NULL || q==NULL) return false;
    else if(p->val==q->val && check(p->left,q->right) && check(q->left,p->right)) return true;
    else return false;
    }
    bool isSymmetric(TreeNode* root) 
    { 
      if(root==NULL) return true;
      return check(root->left,root->right);
    }
};