
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&sortedVec)
    {
    if(root==NULL) return;
    inorder(root->left,sortedVec);
    sortedVec.push_back(root->val);
    inorder(root->right,sortedVec);
    }

     TreeNode* fixValue(TreeNode* root, const vector<int>& sortedVec, const vector<int>& sum, int& i) {
        if (root == NULL) return NULL;

        fixValue(root->left, sortedVec, sum, i);

        if (sortedVec[i] == root->val) {
            root->val = sum[i];
            ++i;
        }

        fixValue(root->right, sortedVec, sum, i);

        return root;
    }


    TreeNode* bstToGst(TreeNode* root) {
    if(root==NULL) return NULL;
    vector<int>sortedVec;
    inorder(root,sortedVec);  
   vector<int> sum(sortedVec.size(), 0);
        sum[sortedVec.size() - 1] = sortedVec[sortedVec.size() - 1];
        for (int i = sortedVec.size() - 2; i >= 0; --i) {
            sum[i] = sum[i + 1] + sortedVec[i];
        }
        int i=0;
    fixValue(root,sortedVec,sum,i);
    return root;
    }
};