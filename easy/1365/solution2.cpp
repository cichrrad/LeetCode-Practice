#include<numeric>

// to avoid O(n^2), we leverge the constrains
// placed on the range of numbers in nums

// [0 <= nums[i] <= 100]
// for such a small set, it is sensible
// to sacrifice memory for this
// declare a vector of size [101] holding
// occurence count for each number on its
// corresponding index
// ie. for value 3, we will count occurences
// at index 3

// then perform inclusive scan on this vector
// to get the occurence count for each number
// smaller than the current number
// paste into answer vector and catch edge case
// for number 0
// --> we cooking

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> occurences(101);
        vector<int> ans(nums.size());

        for (const auto &el : nums){
            occurences[el]++;
        }

        // inclusive scan
        for (int i = 1; i < 101; i++) {
            occurences[i] += occurences[i - 1];
        }
   
        // paste + edqe case for 0
        for (int i = 0; i < nums.size(); i++){
            ans[i] = nums[i] == 0 ? 0 : occurences[nums[i]-1];
        }
        return ans;
    }
};