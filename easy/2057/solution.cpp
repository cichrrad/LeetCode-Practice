class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        //naive -> go over and return first match
        // at most O(n) so we cooking
        for (int i = 0; i<nums.size();i++){
            if (i % 10 == nums[i]){
                return i;
            }
        }
        return -1;
    }
};
