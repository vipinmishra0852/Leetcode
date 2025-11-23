class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: count fresh oranges & push rotten oranges to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int time = -1;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // BFS
        while (!q.empty()) 
        {
            int sz = q.size();
            time++;

            while (sz--) 
            {
                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dirs) 
                {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    // check boundaries & fresh orange
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;  // rot it
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
