class Solution {
public:
    int maxArea(vector<int>& height) 
    {
    int maxarea = -1;
    int i = 0;
    int n = height.size();
    int j = n-1;
    while(i < j)
    {
        int mini = min(height[i],height[j]);
        int area = (j-i)*mini;
        maxarea = max(maxarea,area);
        if(mini == height[i])
        {
            i++;
        }
        else if(mini == height[j])
        {
            j--;
        }
        else i++;
    } 
    return maxarea;
    }
};