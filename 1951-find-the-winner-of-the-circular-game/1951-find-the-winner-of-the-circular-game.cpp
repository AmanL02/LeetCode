class Solution {
public:
    int findTheWinner(int n, int k) {
        queue <int> que;
        for(int i=1;i<=n;i++){
            que.push(i);
        }
        while(que.size()>1){
            for(int j=1;j<=k-1;j++){
                que.push(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
};