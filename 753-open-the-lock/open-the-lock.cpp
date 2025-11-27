class Solution {
public:
    vector<string> generateNeighbor(string s)
    {
        vector<string> result;

        for (int i = 0; i < 4; i++)
        {
            string temp1 = s;
            string temp2 = s;

            // Correct character rotation
            temp1[i] = ((s[i] - '0' + 1) % 10) + '0';
            temp2[i] = ((s[i] - '0' + 9) % 10) + '0';

            result.push_back(temp1);
            result.push_back(temp2);
        }

        return result;
    }

    int openLock(vector<string>& deadends, string target)
    {
        string start = "0000";

        // If start is already dead
        set<string> dead;
        for (auto &d : deadends) dead.insert(d);
        if (dead.count(start)) return -1;

        // If target is start
        if (target == start) return 0;

        queue<string> q;
        set<string> visited;

        q.push(start);
        visited.insert(start);

        int count = 0;

        // BFS
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                string s = q.front();
                q.pop();

                if (s == target) return count;

                vector<string> temp = generateNeighbor(s);

                for (auto &str : temp)
                {
                    if (!visited.count(str) && !dead.count(str))
                    {
                        visited.insert(str);
                        q.push(str);
                    }
                }
            }

            count++;
        }

        return -1; // Impossible
    }
};
