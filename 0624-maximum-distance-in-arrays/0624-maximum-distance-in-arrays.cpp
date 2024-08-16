class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        // greedy
        // compare each mini and maxi with its previous array

        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int n = arrays.size();
        int res = 0;

        for(int i=1; i<n; i++)
        {
            int temp1 = abs(arrays[i].front() - maxi);
            int temp2 = abs(arrays[i].back() - mini);

            mini = min(mini, arrays[i].front());
            maxi = max(maxi, arrays[i].back());

            res = max(res, max(temp1, temp2));
        }

        return res;
    }
};