class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> res;
        
        int total = rows * cols;
        
        // intitial values
        int val = 1;
        int start_i = rStart;
        int end_i = rStart  + 1;
        int start_j = cStart;
        int end_j = cStart + 1;
        
        while(val <= total)
        {   
            //first row
            for(int i=start_j; i<=end_j && val <= total; i++)
            {
                if(start_i >= 0 && start_i < rows && i >= 0 && i < cols)
                {
                    res.push_back({start_i, i});
                    val ++;
                }
            }
            
            //last column
            for(int i=start_i+1; i<=end_i && val <= total; i++)
            {
                if(i >= 0 && i< rows && end_j >= 0 && end_j < cols)
                {
                    res.push_back({i, end_j});
                    val ++;
                }
            }
            start_j --;
            
            //last row
            for(int i=end_j-1; i>=start_j && val <= total; i--)
            {
                if(end_i >= 0 && end_i < rows && i >= 0 &&  i < cols)
                {
                    res.push_back({end_i, i}); 
                    val ++;
                }
                    
            }
            
            //first column
            for(int i=end_i-1; i>=start_i && val <= total; i--)
            {
                if(i >= 0 && i < rows && start_j >= 0 && start_j < cols)
                {
                    res.push_back({i, start_j});
                    val ++;
                }
            }
            
            start_i --;
            end_i ++;
            end_j ++;
        }
        
        return res;
        
    }
};