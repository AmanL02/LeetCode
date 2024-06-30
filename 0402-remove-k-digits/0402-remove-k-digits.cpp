class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        stack<char> st;
        string ans = "";
        for (int i = 0; i < num.size(); i++) {
            while (st.size() > 0 && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        if (start == ans.size()) {
            return "0";
        }
        return ans.substr(start);
    }
};