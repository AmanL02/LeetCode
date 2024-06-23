class Solution {
public:
    bool posible(int day,int m,int k,vector<int>& bloomDay){
        int ans=0, count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                ans+=count/k;
                count=0;
            }
        }
        ans+=count/k;
        return ans>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(long(m)*k>bloomDay.size()) return -1;
        int a=*min_element(bloomDay.begin(),bloomDay.end());
        int b=*max_element(bloomDay.begin(),bloomDay.end());
        int low=a, high=b;
        while(low<=high){
            int mid=(low+high)/2;
            if(posible(mid,m,k,bloomDay)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};