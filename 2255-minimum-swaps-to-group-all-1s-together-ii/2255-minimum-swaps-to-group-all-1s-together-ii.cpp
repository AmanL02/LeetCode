class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalOnes=accumulate(begin(nums),end(nums),0);
        int i=0,j=0;
        int currOnes=0,maxCount=0;
        while(j<2*n){
            if(nums[j%n]==1){
                currOnes++;
            }
            if(j-i+1>totalOnes){
                currOnes-=nums[i%n];
                i++;
            }
            maxCount=max(maxCount,currOnes);
            j++;
        }
        return totalOnes-maxCount;
    }
};