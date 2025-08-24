class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {

    // S ... sum(nums)
    // x ... outlier
    // l ... sum of special numbers

    // we know, that:
    //                l = S - x - l (ie. Sum of all elements - outlier - sum of special nums)
    // from that -->  x = S - 2l

    // we select some [l], which defines [x] --> if it is in nums, we take it 

    long long S = accumulate(nums.begin(),nums.end(),0);
    unordered_map<int,int> occurences;

    //count up occurences of elements
    for (auto &i : nums){
        ++occurences[i]; //seeing element i --> add 1 to bucket keyed with i
    }

    int maxX = INT_MIN;

    // select element from nums as [l]
    for(auto &l : nums){
        //treating l as sum element
        //(= cannot be same index as x)
        --occurences[l];

        int x = S - (2*l); // [x] MUST be this number (if exists)
        if(occurences[x]) {
            maxX = max(maxX,x); // update if this is largest found to date 
        }
         ++occurences[l]; // restore l
    }

    return maxX;
    
    }
};
