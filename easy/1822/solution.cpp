class Solution {
public:
    int arraySign(vector<int>& nums) {
    int minusCount = 0;
    for (auto &num : nums){
        if (num){
            if (num < 0){
                minusCount ^=1;
            }
        } 
        else{
            return 0;
        }
    }
        // is 0 iff minusCount is odd --> -1
        if (minusCount){
            return -1;
        }
        return 1;
    }
};
