// class Solution {
// public:
//     int nthUglyNumber(int n) {

//         set<int> st;
//         st.insert(1);
//         int i=1;
//         while(true){
//             set<int> st2=st;
//             if(i>=n*3) break;
//             for(auto m=st2.begin();m!=st2.end();m++){
//                 if(st.find(2*(*m))==st.end()){
//                     st.insert(2*(*m));
//                     i++;
//                 }
//                 if(st.find(3*(*m))==st.end()){
//                     st.insert(3*(*m));
//                     i++;
//                 }
//                 if(st.find(5*(*m))==st.end()){
//                     st.insert(5*(*m));
//                     i++;
//                 }
//             }
//         }
//         int ans=0;
//         int k=1;
//         for(auto j=st.begin();j!=st.end();j++){
//             if(k==n){
//                 ans=*j;
//             }
//             k++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        
        // use priority queue to only insert the smallest number from each iteration to the res

        vector <long long> arr;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set <long long> st;
        
        vector <int> primes = {2, 3, 5};
        st.insert(1);
        pq.push(1);
        long long res = 1;
    
        for(int i=0; i<n; i++)
        {
            res = pq.top();
            pq.pop();

            for(auto p: primes)
            {
                long long temp = p * res;
                if(!st.count(temp))
                {
                    pq.push(temp);
                    st.insert(temp);
                }      
            }
        }
        return res;
    }
};