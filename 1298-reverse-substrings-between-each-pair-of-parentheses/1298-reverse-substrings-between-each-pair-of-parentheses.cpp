class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                temp[i] = j;
                temp[j] = i;
            }
        }
        string ans;
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=temp[i];
                flag=-flag;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};