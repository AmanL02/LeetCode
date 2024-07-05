class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 'A'; i <= 'Z'; i++) {
            int swaps = 0;
            int i1 = 0;
            int j1 = 0;
            int curr = 0;
            while (j1 < s.length()) {
                if (s[j1] != i)
                    swaps++;
                while (swaps > k) {
                    if (s[i1] != i)
                        swaps--;
                    i1++;
                }
                curr = max(curr, j1 - i1 + 1);
                j1++;
            }
            res = max(res, curr);
        }
        return res;
    }
};