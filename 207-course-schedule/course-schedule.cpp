class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // Initialize the graph as an adjacency list
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph and calculate indegrees
        for (const auto& pre : prerequisites) {
            int a = pre[0]; // Course to be taken
            int b = pre[1]; // Prerequisite course
            graph[b].push_back(a); // b must be taken before a
            indegree[a]++; // Increase indegree of course a
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Count of courses that can be finished
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            count++; // A course is finished

            // Decrease indegree for all neighbors
            for (int neighbour : graph[n]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour); // If indegree is 0, add to queue
                }
            }
        }

        // If count equals number of courses, return true
        return count == numCourses;
    }
};
