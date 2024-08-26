class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timer = 0;
        queue<pair<pair<int, int>, int>> qt; // Stores the coordinates and time of rotting
        int n = grid.size();
        int m = grid[0].size();

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    qt.push({{i, j}, timer});
                }
            }
        }

        int result = 0;
        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // Directions: left, up, right, down

        // BFS to process rotting of adjacent fresh oranges
        while (!qt.empty()) {
            auto current = qt.front();
            qt.pop();
            int x = current.first.first;
            int y = current.first.second;
            int t = current.second;
            result = max(result, t);

            for (auto it : dir) {
                int xn = x + it.first;
                int yn = y + it.second;

                // Check if within grid boundaries and if it is a fresh orange
                if (xn >= 0 && yn >= 0 && xn < n && yn < m && grid[xn][yn] == 1) {
                    grid[xn][yn] = 2; // Mark as rotten
                    qt.push({{xn, yn}, t + 1}); // Push with updated time
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // Not all oranges can rot
                }
            }
        }

        return result; // Return the time taken to rot all oranges
    }
};
