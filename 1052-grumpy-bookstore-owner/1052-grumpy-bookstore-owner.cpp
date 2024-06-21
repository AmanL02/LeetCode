class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int max_sum=0, sum=0;
        for(int i=0;i<m;i++){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
        }
        max_sum=sum;
        int i=0, j=m;
        while(j<customers.size()){
            if(grumpy[j]==1){
                sum+=customers[j];
            }
            if(grumpy[i]==1){
                sum-=customers[i];
            }
            max_sum=max(max_sum,sum);
            i++;
            j++;
        }
        int temp_sum=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0){
                temp_sum+=customers[i];
            }
        }
        int ans=max_sum+temp_sum;
        return ans;
    }
};