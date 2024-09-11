class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int mistakes = 0;
        
        for(int i = 1;i<nums.size();i++){
            
            //mistake
            if(nums[i-1]>=nums[i]){
                if(mistakes==1){

                    return false;
                }
                mistakes++;

                //if possible,move ahead
                if(i>1 && nums[i]<=nums[i-2]){
                    nums[i]= nums[i-1];           
                }                              
            }
            //continue
        }
        return true;
    }
};
