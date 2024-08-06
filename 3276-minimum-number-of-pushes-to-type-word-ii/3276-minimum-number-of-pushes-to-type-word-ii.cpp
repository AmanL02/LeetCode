class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> temp(26,0);
        for(int i=0;i<n;i++){
            temp[word[i]-'a']++;
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int result=0;
        for(int i=0;i<26;i++){
            if(i<8){
                result+=1*temp[i];
            }
            else if(i<16){
                result+=2*temp[i];
            }
            else if(i<24){
                result+=3*temp[i];
            }
            else{
                result+=4*temp[i];
            }
        }
        return result;
    }
};