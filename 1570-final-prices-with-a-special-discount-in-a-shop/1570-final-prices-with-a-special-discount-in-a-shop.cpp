class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        stack<int> st;
        for(int i=prices.size()-1;i>=0;i--){
            if(st.size()==0){
                ans.push_back(prices[i]);
            }
            else if(st.size()>0 && prices[i]>=st.top()){
                ans.push_back(prices[i]-st.top());
            }
            else if(st.size()>0 && prices[i]<st.top()){
                while(st.size()>0 && prices[i]<st.top()){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(prices[i]);
                }else{
                    ans.push_back(prices[i]-st.top());
                }
            }
            st.push(prices[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};