class Solution {
public:
    int largestRectangleArea(vector<int> arr) {
        int n = arr.size();
        vector<int> right;
        vector<int> left;
        stack<pair<int, int>> sr;
        stack<pair<int, int>> sl;
        for (int i = n - 1; i >= 0; i--) {
            if (sr.size() == 0) {
                right.push_back(n);
            } else if (sr.size() > 0 && sr.top().first < arr[i]) {
                right.push_back(sr.top().second);
            } else if (sr.size() > 0 && sr.top().first >= arr[i]) {
                while (sr.size() > 0 && sr.top().first >= arr[i]) {
                    sr.pop();
                }
                if (sr.size() == 0) {
                    right.push_back(n);
                } else {
                    right.push_back(sr.top().second);
                }
            }
            sr.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        for (int i = 0; i < n; i++) {
            if (sl.size() == 0) {
                left.push_back(-1);
            } else if (sl.size() > 0 && sl.top().first < arr[i]) {
                left.push_back(sl.top().second);
            } else if (sl.size() > 0 && sl.top().first >= arr[i]) {
                while (sl.size() > 0 && sl.top().first >= arr[i]) {
                    sl.pop();
                }
                if (sl.size() == 0) {
                    left.push_back(-1);
                } else {
                    left.push_back(sl.top().second);
                }
            }
            sl.push({arr[i], i});
        }
        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * width[i];
            ans = max(ans, arr[i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    temp[j] = 0;
                } else {
                    temp[j] += 1;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(temp));
        }
        return maxArea;
    }
};