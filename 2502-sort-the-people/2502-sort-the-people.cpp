class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mpp;
        int n=heights.size();
        for(int i=0;i<n;i++){
            mpp[heights[i]]=names[i];
        }
        vector<string> ans;
        for(auto i=mpp.begin();i!=mpp.end();i++){
            ans.push_back(i->second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};