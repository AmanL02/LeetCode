class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count=0,count=0;
        int i=0,j=0;
        unordered_map<char,int> mpp;
        while(j<s.size()){
            if(mpp.find(s[j])!=mpp.end() && mpp[s[j]]>=i){
                i=mpp[s[j]]+1;
            }
            mpp[s[j]]=j;
            count=j-i+1;
            max_count=max(max_count,count);
            j++;
        }
        return max_count;
    }
};