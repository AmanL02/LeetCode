class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgr(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                revgr[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> qt;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                qt.push(i);
            }
        }

        vector<int> ans;

        while (!qt.empty()) {
            int node = qt.front();
            qt.pop();
            ans.push_back(node);

            for (auto it : revgr[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qt.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};