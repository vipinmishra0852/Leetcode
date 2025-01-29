class Solution {
public:

    // Helper function to detect cycle using DFS
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited)) {
                    return true;  // Cycle found
                }
            } else if (neighbor != parent) {
                return true;  // Cycle found
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);  // 1-based indexing

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];

            // Add edge temporarily
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Check if this edge forms a cycle
            vector<bool> visited(n + 1, false);
            if (dfs(u, -1, adj, visited)) {
                return {u, v};  // Found redundant edge
            }
        }
        return {};
    }

// Driver Code


};