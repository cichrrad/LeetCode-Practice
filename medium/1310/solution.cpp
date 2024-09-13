class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto const &q : queries){
            int curr = q[0];
            int end = q[1];
            //edge case - size 1
            if (curr == end){
                ans.push_back(arr[curr]);
                continue;
            }
            
            int temp = -1;
            do{
                temp = (temp == -1 ? arr[curr] ^ arr[curr+1] : temp ^ arr[curr+1]);
                curr++;
            }while(curr!=end);
            ans.push_back(temp);
        }
        return ans;
    }
};
