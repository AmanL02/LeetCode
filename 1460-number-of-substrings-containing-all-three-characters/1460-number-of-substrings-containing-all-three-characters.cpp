class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int ans = 0;
        while (j < s.size()) {
            mpp[s[j]]++;
            while (mpp.size() == 3) {
                ans += s.size() - j;
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};