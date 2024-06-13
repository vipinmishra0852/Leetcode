class Solution {
public:
    TreeNode* build(vector<int>& in, int inLo, int inHi, vector<int>& post, int postLo, int postHi) {
        if (inLo > inHi) return nullptr;
        TreeNode* root = new TreeNode(post[postHi]);
        if (inLo == inHi) return root;

        int i = inLo;
        while (i < inHi) {
            if (in[i] == post[postHi]) break;
            i++;
        }

        int leftcount = i - inLo;
        int rightcount = inHi - i;

        root->left = build(in, inLo, i - 1, post, postLo, postLo + leftcount - 1);
        root->right = build(in, i + 1, inHi, post, postLo + leftcount, postHi - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in, 0, n - 1, post, 0, n - 1);
    }
};