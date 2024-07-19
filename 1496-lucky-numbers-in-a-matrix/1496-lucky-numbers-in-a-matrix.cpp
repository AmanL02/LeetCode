class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            int mini=INT_MAX;
            int index=-1;
            for(int j=0;j<matrix[0].size();j++){
                if(mini>matrix[i][j]){
                    mini=matrix[i][j];
                    index=j;
                }
            }
            bool flag=false;
            for(int k=0;k<matrix.size();k++){
                if(mini<matrix[k][index]){
                    flag=false;
                    break;
                }else{
                    flag=true;
                }
            }
            if(flag){
                ans.push_back(mini);
            }
        }
        return ans;
    }
};