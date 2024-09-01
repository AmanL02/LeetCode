class Solution {
private:
    bool dfs(int node,int rang,vector<int>& col,vector<vector<int>>& graph){
        col[node]=rang;
        for(auto it: graph[node]){
            if(col[it]==-1){
                if(dfs(it,!rang,col,graph)==false){
                    return false;
                }
            }else if(rang==col[it]){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};