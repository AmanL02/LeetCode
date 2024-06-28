class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<2*n;i++){
            temp.push_back(nums[i%n]);
        }
        stack<int> st;
        vector<int> temp2;
        for(int i=temp.size()-1;i>=0;i--){
            if(st.size()==0){
                temp2.push_back(-1);
            }
            else if(st.size()>0 && st.top()>temp[i]){
                temp2.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=temp[i]){
                while(st.size()>0 && st.top()<=temp[i]){
                    st.pop();
                }
                if(st.size()==0){
                    temp2.push_back(-1);
                }else{
                    temp2.push_back(st.top());
                }
            }
            st.push(temp[i]);
        }
        reverse(temp2.begin(),temp2.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(temp2[i]);
        }
        return ans;
    }
};