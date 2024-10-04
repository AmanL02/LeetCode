class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int temp=skill[0]+skill[n-1];
        int i=0,j=n-1;
        while(i<j){
            if(skill[i]+skill[j]==temp){
                ans+=skill[i]*skill[j];
                i++;
                j--;
            }else{
                return -1;
            }
        }
        return ans;
    }
};