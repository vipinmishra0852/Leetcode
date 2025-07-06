class FindSumPairs {
public:
 map<int,int>mp; 
 vector<int>v1;
 vector<int>v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
      v1 = nums1;
      v2 = nums2;
      for(int num:v2)
      {
        mp[num]++;
      }
    }
    
    void add(int index, int val) 
    {
     mp[v2[index]]--;
     v2[index] = v2[index] + val;   
     mp[v2[index]]++;
    }
    
    int count(int tot) 
    {
    int res = 0;
    for(int num:v1)  
    {
    int b = tot - num;
    if(mp.count(b))
    {
        res = res + mp[b];
    }   
    } 
    return res; 
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */