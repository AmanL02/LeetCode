class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left;
        vector<int> right;
        int x=1;
        left.push_back(1);
        right.push_back(1);
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1]){
                x=x+1;
                left.push_back(x);
            }else{
                x=1;
                left.push_back(1);
            }
        }
        x=1;
        for(int i=n-1;i>0;i--){
            if(ratings[i]<ratings[i-1]){
                x=x+1;
                right.push_back(x);
            }else{
                x=1;
                right.push_back(1);
            }
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<n;i++){
            cout<< left[i]<< " ";
            cout<< right[i]<< " ";
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};