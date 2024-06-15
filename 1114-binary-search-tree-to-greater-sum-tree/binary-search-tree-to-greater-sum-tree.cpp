
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&sortedVec)
    {
    if(root==NULL) return;
     inorder(root->right,sortedVec);
     sortedVec.push_back(root->val);
    inorder(root->left,sortedVec);
    ;
   
    }

     TreeNode* fixValue(TreeNode* root, const vector<int>& sortedVec, const vector<int>& sum, int& i) {
        if (root == NULL) return NULL;

      
   fixValue(root->right, sortedVec, sum, i);
        if (sortedVec[i] == root->val) {
            root->val = sum[i];
            ++i;
        }

       fixValue(root->left, sortedVec, sum, i);

        return root;
    }


    TreeNode* bstToGst(TreeNode* root) {
    if(root==NULL) return NULL;
    vector<int>sortedVec;
    inorder(root,sortedVec);  
    int n=sortedVec.size();
   vector<int> sum(sortedVec.size(), 0);
        sum[0] = sortedVec[0];
        for (int i=1; i < n; i++) {
            sum[i] = sum[i - 1] + sortedVec[i];
        }
        int i=0;
    fixValue(root,sortedVec,sum,i);
    return root;
    }
};