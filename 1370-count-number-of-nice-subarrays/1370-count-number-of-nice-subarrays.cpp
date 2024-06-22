class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
        unordered_map<int,int> mpp;
        int sum=0,count=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.count(sum-k)) count+=mpp[sum-k];
            mpp[sum]++;
        }
        return count;
    }
};