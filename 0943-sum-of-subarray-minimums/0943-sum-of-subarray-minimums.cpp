class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);
        stack<pair<int, int>> st;

        // Compute right limits
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top().second;
            }
            st.push({arr[i], i});
        }

        // Clear stack for reuse
        while (!st.empty())
            st.pop();

        // Compute left limits
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top().second;
            }
            st.push({arr[i], i});
        }

        long long ans = 0;
        int MOD = 1e9 + 7;

        // Calculate result
        for (int i = 0; i < n; ++i) {
            long long contribution =
                (long long)arr[i] * (i - left[i]) * (right[i] - i);
            ans = (ans + contribution) % MOD;
        }

        return (int)ans;
    }
};
