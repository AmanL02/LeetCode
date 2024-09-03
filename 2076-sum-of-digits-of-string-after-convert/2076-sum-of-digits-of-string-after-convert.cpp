class Solution {
public:
    int getLucky(string s, int k) {
        
        string res = "";
        for(auto ch: s)
        {
            int temp = ch - 'a' + 1;
            res += to_string(temp);
        }

        int ans = 0;
        while(k--)
        {
            ans = 0;
            for(auto ch: res)
            {
                ans += ch - '0';
            }
            res = to_string(ans);
        }
        return ans;
    }
};