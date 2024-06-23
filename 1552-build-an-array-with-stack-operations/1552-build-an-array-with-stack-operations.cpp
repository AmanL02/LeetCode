class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<int> temp;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(temp==target) return ans;

            if(i==target[j]){
                temp.push_back(i);
                ans.push_back("Push");
                j++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};