class Solution {
public:
    int longestSubarray(vector<int>& nums) {

    
    const int size = nums.size();
    //find first max 
    int maxIndex = -1;
    int maxVal = -1;
    for(int i = 0; i<size;i++){
        if (nums[i] > maxVal){
            maxIndex = i;
            maxVal = nums[i];
        }
    }
    //find longest sequence of max
    int ans = 0;
    for(int i = maxIndex; i<size;i++){
        
        int currSeqLen = 0;
        //if on maxVal element, try to
        //traverse maxVal sequence (if it is there)
        while(i<size && nums[i] == maxVal){
            currSeqLen++;
            i++;
        }
        //check if this sequence was longer than max
        ans = std::max(ans,currSeqLen);
    }
    return ans;

    }
};
