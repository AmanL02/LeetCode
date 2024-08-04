class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD=1e9+7;
        vector<long long> temp;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        while(left<=right){
            ans+=temp[left-1];
            left++;
        }
        return ans%MOD;
    }
};