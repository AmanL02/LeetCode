class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> indexR(n);
        vector<int> indexL(n);
        vector<int> res(n);
        indexR = NSR(heights);
        indexL = NSL(heights);
        for(int i = 0; i < n; i++){
            res[i] = (indexR[i] - indexL[i] - 1) * heights[i];
        }
        int max = 0;
        for(int i = 0; i < n; i++){
            if(res[i] > max)
            {
                max = res[i];
            }
        }
        return max;
    }

    vector<int> NSR(vector<int> h){
        stack<pair<int,int>> st;
        int n = h.size();
        vector<int> index(n);
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                st.push({h[i],i});
                index[i] = n;
            }
            else if(st.top().first < h[i]){
                index[i] = st.top().second;
                st.push({h[i],i});
            }
            else if(st.top().first >= h[i]){
                while(!st.empty() && st.top().first >= h[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push({h[i],i});
                    index[i] = n;
                }
                else if(st.top().first < h[i]){
                    index[i] = st.top().second;
                    st.push({h[i],i});
                }
            }
        }
        return index;
    }

        vector<int> NSL(vector<int> h){
        stack<pair<int,int>> st;
        int n = h.size();
        vector<int> index(n);
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({h[i],i});
                index[i] = -1;
            }
            else if(st.top().first < h[i]){
                index[i] = st.top().second;
                st.push({h[i],i});
            }
            else if(st.top().first >= h[i]){
                while(!st.empty() && st.top().first >= h[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push({h[i],i});
                    index[i] = -1;
                }
                else if(st.top().first < h[i]){
                    index[i] = st.top().second;
                    st.push({h[i],i});
                }
            }
        }
        return index;
    }
};