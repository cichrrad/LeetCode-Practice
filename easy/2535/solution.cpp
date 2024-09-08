class Solution {
public:
    int differenceOfSum(vector<int>& nums) {

        //do both at once like a baller
        int diff = 0;
        for (unsigned int i = 0; i < nums.size(); i++){
            unsigned int n = nums[i];
            //adding sum to diff
            diff += n;
            //subtracting digit sum from it
            while (n > 0){
                unsigned int digit = n % 10;
                diff -=digit;
                n /= 10;
            }


        }
        //return absolute
        return diff < 0 ? (diff*-1):(diff);

    }
};
