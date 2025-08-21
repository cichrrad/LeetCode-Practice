class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        //greedy left-->right pass
        
        //any action affects all right indices
        //--> when we are at index [i] which is 0
        // we MUST flip as no future operation will
        // fix it (as it will be to the right of [i])
        

        //operations taken
        unsigned int ops = 0;
        //parity of # of flips (even/odd)
        unsigned int parity = 0;
        
        
        for (auto b : nums){
    
            if (b==parity){
                ops++;
                parity ^=1; 
            }
        }
        return ops;
    }
};
