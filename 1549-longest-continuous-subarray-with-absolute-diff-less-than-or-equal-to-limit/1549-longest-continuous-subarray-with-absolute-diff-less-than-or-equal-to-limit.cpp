class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset <int> mpp;
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            mpp.insert(nums[j]);
            while(*mpp.rbegin()-*mpp.begin()>limit){
                mpp.erase(mpp.find(nums[i]));
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};