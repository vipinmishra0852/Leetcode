class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
    bool res = 0;
for(auto it:derived)
{
    res = res ^ it;
}
return res == 0;
    }
};