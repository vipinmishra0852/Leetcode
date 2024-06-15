
class Solution {
public:
    TreeNode* helper(vector<int>&nums,int lo,int hi)
    {
      if(lo>hi) return NULL;
      int mid=lo+(hi-lo)/2;
      TreeNode* root = new TreeNode(nums[mid]);  
      root->left = helper(nums,lo,mid-1);
      root->right = helper(nums,mid+1,hi);
      return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {int lo=0;
    int hi=nums.size();
     return helper(nums,lo,hi-1);   
    }
};