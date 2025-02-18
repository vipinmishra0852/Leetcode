class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,1}, {1,-1}, {1,1}, {-1,-1}};

    bool is_Safe(int x, int y, vector<vector<int>>& grid) {
        return (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0);
    }

    using p = pair<int, int>;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;

        queue<p> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Mark as visited
        int count = 1;    // Path length starts at 1

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current BFS level

            for (int k = 0; k < levelSize; k++) {  // Process all nodes at the current level
                p t = q.front();
                q.pop();
                int i = t.first, j = t.second;

                if (i == m - 1 && j == n - 1) return count;  // Reached the destination

                for (auto dir : directions) {
                    int x_ = i + dir[0];
                    int y_ = j + dir[1];

                    if (is_Safe(x_, y_, grid)) {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;  // Mark as visited to avoid duplicate processing
                    }
                }
            }
            count++;  // Increment path length after processing the entire level
        }

        return -1;  // No path found
    }
};
