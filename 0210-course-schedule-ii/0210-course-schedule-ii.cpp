class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<std::vector<int>> adj(numCourses);
        vector<int> topo;
        for (const auto& it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course);
        }

        for (const auto& it : prerequisites) {
            int course = it[0];
            indegree[course]++;
        }

        queue<int> qt;
        for (int j = 0; j < numCourses; j++) {
            if (indegree[j] == 0) {
                qt.push(j);
            }
        }

        while (!qt.empty()) {
            int node = qt.front();
            topo.push_back(node);
            qt.pop();
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qt.push(it);
                }
            }
        }

        if( topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};