class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        int count=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1 && count==k){
                return arr[i];
            }else if(mpp[arr[i]]==1){
                count++;
            }
        }
        return "";
    }
};