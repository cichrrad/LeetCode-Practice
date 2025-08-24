class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // two pointers at offset [n] approach...
        vector<int> res;
        for(int i = 0; i < n ;i++){
            // l = i
            // r = i+n
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
            
        }
        return res;
    }
};
