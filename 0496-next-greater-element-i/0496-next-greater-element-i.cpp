class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> mpp;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]=i;
        }
        vector<int> temp;
        for(int i=0;i<nums1.size();i++){
            temp.push_back(mpp[nums1[i]]);
        }
        vector<int> temp2;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.size()==0){
                temp2.push_back(-1);
            }
            else if(st.size()>0 && st.top()>nums2[i]){
                temp2.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=nums2[i]){
                while(st.size()>0 && st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.size()==0){
                    temp2.push_back(-1);
                }else{
                    temp2.push_back(st.top());
                }
            }
            st.push(nums2[i]);
        }
        reverse(temp2.begin(),temp2.end());
        vector<int> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp2[temp[i]]);
        }
        return ans;
    }
};