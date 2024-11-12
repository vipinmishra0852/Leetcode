
class Solution
{
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    int row = items.size();
    map<int, int> m;

   
    for (int i = 0; i < row; i++)
    {
      int p = items[i][0];
      int b = items[i][1];
      if (m.find(p) != m.end())
      {
        if (b > m[p])
        {
          m[p] = b;
        }
      }
      else
      {
        m[p] = b;
      }
    }

  

    int max_beauty = 0;
    for (auto &it : m)
    {
      max_beauty = max(max_beauty, it.second);
      it.second = max_beauty;
    }


    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
      auto it = m.upper_bound(queries[i]);
      if (it == m.begin())
      {
        ans.push_back(0);
      }
      else
      {
        --it;
        ans.push_back(it->second);
      }
    }
    return ans;
  }
};