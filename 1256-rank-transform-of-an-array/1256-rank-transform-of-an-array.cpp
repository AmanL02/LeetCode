class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mpp;
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        int count = 1;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]]=count;
                count++;
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mpp[temp[i]]);
        }
        return ans;
    }
};