
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Initialize the queue with all the initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
          q.push({-1,-1});
        if (fresh == 0) return 0; // No fresh oranges to rot
        
        int minutes = 0; 
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS to simulate the rotting process
        while (!q.empty()) 
        {
            auto cell = q.front();
            q.pop();
            if(cell.first == -1 && cell.second == -1)
            {
                minutes++;
                if(!q.empty())
                {
                    q.push({-1,-1});
                }
                else {break;}
            }
            else
            {
              int i = cell.first;
              int j = cell.second;
              for(int  d = 0 ; d < 4 ;d++)
              {
                int nr = i + directions[d][0];
                int nc = j + directions[d][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                fresh--;
                grid[nr][nc] = 2;
                q.push({nr,nc});

              }

            }
            
        }

        return fresh == 0 ? minutes-1 : -1;
    }
};