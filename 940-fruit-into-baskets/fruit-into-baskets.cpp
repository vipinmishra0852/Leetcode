class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int srt = 0;
    int maxlength = 0;
    unordered_map<int,int>mp;
    for(int end = 0; end < fruits.size();end++)
    {
        mp[fruits[end]]++;
        while(mp.size() > 2)
        {
            mp[fruits[srt]]--;
             if(mp[fruits[srt]] == 0) mp.erase(fruits[srt]);
            srt++;
        }
       
       
        maxlength = max(maxlength,end - srt + 1);
    }
    return maxlength;
        
    }
};