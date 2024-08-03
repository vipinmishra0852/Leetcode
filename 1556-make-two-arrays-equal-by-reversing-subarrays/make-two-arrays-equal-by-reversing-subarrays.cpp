class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
      int ele = 0;
      int n = arr.size();
      map<int,int>m1;
      map<int,int>m2;
      for(int i = 0 ; i < n ; i++)
      {
        if(arr[i] != target[i])
        {
            ele++;
        }
        m1[arr[i]]++;
        m2[target[i]]++;
      }
      if(m1 != m2) return false;
      else if(m1 == m2 && ele == 1) return false;
  
      return true;  
    }
};