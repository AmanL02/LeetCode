class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(ans.size());
            }
            else if(s[i]==')'){
                reverse(ans.begin()+st.top(),ans.end());
                st.pop();
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};