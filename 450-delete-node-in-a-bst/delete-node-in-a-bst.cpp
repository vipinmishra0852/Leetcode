
class Solution {
public:
    TreeNode* iop(TreeNode* root)
    {
        TreeNode* pred = root->left;
        while(pred->right!=NULL)
        {
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode* root)
    {
        TreeNode* succ=root->right;
        while(succ->left!=NULL)
        {
            succ=succ->left;
        }
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
     if(root==NULL) return NULL;   
     if(root->val==key)
     {
        // case:1 No child
       if(root->left==NULL && root->right==NULL)
       {
        return NULL;
       }
       // case: 2:-> 1 child 
       if(root->left==NULL || root->right==NULL)
       {
          if(root->left != NULL) return root->left;
          else return root->right;    
       }

       // case 3 :-> 2 child 

       if(root->left!=NULL && root->right!=NULL)
       {
        TreeNode* pred = iop(root);
        root->val=pred->val;
        root->left = deleteNode(root->left,pred->val);  
       }
     }
     else if(root->val > key )
     {
        root->left = deleteNode(root->left,key);
     }
     else
     {
       root->right = deleteNode(root->right,key); 
     }
     return root;
    }
};