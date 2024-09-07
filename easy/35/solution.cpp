
//literally just a binary search to get O(logn) time complexity

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        
        int pivot,l,p;
        l = 0;
        p = nums.size()-1;
        

        while(l<=p){
            pivot = (l+p)/2;
            
            if(nums[pivot]==target){
                return pivot;
            }
            if(nums[pivot]<target){
                l = pivot + 1;
            }
            if(nums[pivot]>target){
                p = pivot - 1;
            }
        }
        return (nums[pivot]<target) ? pivot+1 : pivot;
    }
};
