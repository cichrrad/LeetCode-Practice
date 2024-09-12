class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> row, col;        
        std::reverse(queries.begin(), queries.end()); 
        long long sum = 0; 

        for (auto query : queries) 
        {            
            int type = query[0]; 
            int index = query[1];
            int value = query[2]; 
            if (type == 0) 
            {
                if (row.count(index) == 0) {
                   
                sum += static_cast<long long>(n - col.size()) * value;
        
                  row.insert(index);
                }
           } else { 

               if (col.count(index) == 0) {
                  sum += static_cast<long long>(n - row.size()) * value;
                  col.insert(index);
               }
           }
      }
       return sum; 
    }
};
