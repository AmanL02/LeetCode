class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        int n=details.size();
        for(int i=0;i<n;i++){
            string temp=details[i].substr(11,2);
            int temp2=stoi(temp);
            if(temp2>60 && temp2<100){
                ans++;
            }
        }
        return ans;
    }
};