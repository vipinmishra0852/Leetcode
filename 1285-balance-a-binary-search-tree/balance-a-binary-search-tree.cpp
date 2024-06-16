class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    TreeNode* solve(int low, int high, vector<TreeNode*>& v) {
        if (low > high) return nullptr;
        int mid = (low + high) / 2;
        v[mid]->left = solve(low, mid - 1, v);
        v[mid]->right = solve(mid + 1, high, v);
        return v[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        return solve(0, v.size() - 1, v);
    }
};