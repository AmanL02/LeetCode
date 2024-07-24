class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<int> temp=nums;
        vector<pair<int,int>> mpp;
        for(int i=0;i<nums.size();i++){
            string tempi=to_string(temp[i]);
            int n=tempi.size();
            string demo="";
            for(int j=0;j<n;j++){
                int index=tempi[j] -'0';
                char ch='0'+ mapping[index];
                demo.push_back(ch);
            }
            int prani=stoi(demo);
            mpp.push_back({prani,i});
        }
        stable_sort(mpp.begin(),mpp.end());
        for(auto i=mpp.begin();i!=mpp.end();i++){
            ans.push_back(nums[i->second]);
        }
        return ans;
    }
};