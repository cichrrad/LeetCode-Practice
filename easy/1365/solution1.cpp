

//naive approach - just check for each element lmfao
//O(n^2) 
//not great

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        auto size = nums.size();
        vector<int> ans(size);
        
        for (int i = 0; i < size; i++){

            int currEl = nums[i];

            for(int j = 0; j < size; j++){

                if(nums[j]<currEl){

                    ans[i]++;
                }
            }
        }

        return ans;

    }
};