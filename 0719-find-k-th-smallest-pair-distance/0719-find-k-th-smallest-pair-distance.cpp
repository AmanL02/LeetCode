class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                temp.push_back(abs(nums[i]-nums[j]));
            }
        }
        nth_element(temp.begin(),temp.begin()+(k-1),temp.end());
        return temp[k-1];
    }
};