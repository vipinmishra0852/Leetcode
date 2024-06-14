class Solution {
public:
    long long maxi(TreeNode* root) {
        if(root == nullptr) return LLONG_MIN; // Use LLONG_MIN for long long type
        return max((long long)root->val, max(maxi(root->left), maxi(root->right)));
    }

    long long mini(TreeNode* root) {
        if(root == nullptr) return LLONG_MAX; // Use LLONG_MAX for long long type
        return min((long long)root->val, min(mini(root->left), mini(root->right)));
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->left != nullptr && root->val <= maxi(root->left)) return false; // Correct the type casting
        if(root->right != nullptr && root->val >= mini(root->right)) return false; // Correct the type casting
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
