class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        set<long long> tmp(nums.begin(),nums.end());
               
        int best_chain = 1;
        long long max = 3037000499LL;
        
        for(auto &el : tmp){
            int c = 1;
            long long idx =el*el;
            while(true){
                if(tmp.contains(idx)){
                    c++;
                    idx = idx*idx;
                }
                else{
                    best_chain = (best_chain > c ? best_chain : c);
                    break;
                }
            }
        }

        return (best_chain > 1? best_chain : -1);
    }
};
