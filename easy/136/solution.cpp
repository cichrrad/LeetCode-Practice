//naive - sort and find the first
//element which does not repeat
//good enough, but not linear

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        std::sort(nums.begin(),nums.end());
        unsigned int size = nums.size();

        if(size == 1){
            return nums[0];
        }

        for(int i = 1; i < size;i+=2){
            if(nums[i-1]!=nums[i]){
                return nums[i-1];
            }
        }
        return nums[size-1];
    }
};
