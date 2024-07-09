class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int wat=0;
        for(int i=0;i<customers.size();i++){
            if(wat<customers[i][0]){
                wat=customers[i][0]+customers[i][1];
            }
            else{
                wat+=customers[i][1];
            }
            ans+=wat-customers[i][0];
        }
        int size=customers.size();
        ans=ans/size;
        return ans;
    }
};