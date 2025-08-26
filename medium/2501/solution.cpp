class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        set<long long> tmp(nums.begin(),nums.end());
               
        int best_chain = 1;
        
        for(auto &el : tmp){
            
            int c = 1;
            long long idx =el*el;
            while(tmp.count(idx)){
                c++;
                idx = idx*idx;

            }
            
            best_chain = (best_chain > c ? best_chain : c);
        }

        return (best_chain > 1 ? best_chain : -1);
    }
};
