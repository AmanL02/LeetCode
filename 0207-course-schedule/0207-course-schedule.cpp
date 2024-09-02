#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> indegree(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses); // Initialize adjacency list
        std::vector<int> topo; // Topological order of courses

        // Building the adjacency list
        for (const auto& it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course); // prerequisite course points to course
        }
        
        // Calculating indegree of each node
        for (const auto& it : prerequisites) {
            int course = it[0];
            indegree[course]++;
        }
        
        std::queue<int> qt;
        // Push nodes with zero indegree into the queue
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
        
        return topo.size() == numCourses; // If all courses are in topo sort, then we can finish all courses
    }
};
