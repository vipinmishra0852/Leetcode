class Solution {
public:
    int numRescueBoats(vector<int>& arr, int l) 
    {   
        int n = arr.size();
        int i = 0; 
        int j = n-1;
        int count = 0;
        sort(arr.begin(),arr.end());
        while( i<j )
        { 
          if( arr[i] + arr[j] <= l)
         {
            count++;
            i++;
            j--;
         }
          if(arr[i] + arr[j] > l)
         {
            count++;
            j--;
         }
          if(i==j) 
         {
            count++;
            break;
         }
        }
        return count;
    }
};