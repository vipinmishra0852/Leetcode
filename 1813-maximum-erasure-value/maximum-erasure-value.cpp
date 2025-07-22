class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr)
    {
     int score = 0;
     map<int,int>mp;
     set<int>st;
     int n = arr.size();
     int i = 0 ;
     int j = 0;  
     int sum = 0; 
     
     while( j < n)
     {
       if(  st.find(arr[j]) == st.end() ) // jb na mila
       {
        sum += arr[j];
        score = max(score,sum);
        st.insert(arr[j]);
        mp[arr[j]] = j;
        j++;
       }
       else{ // jb mil gya
       
        int idx = mp[arr[j]];
        while( i<= idx)
        {
            sum-=arr[i];
            st.erase(arr[i]);
            i++;
        }
       }
     }
     return score;
    }
};