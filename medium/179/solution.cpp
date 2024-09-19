class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // int -> string
        std::vector<std::string> sNums;
        for (int num : nums) {
            sNums.push_back(std::to_string(num));
        }

        //decide on the order of elements based on Lex. order
        //(for strings with only numbers Lex. order == value sort)
        //desc. order 
        sort(sNums.begin(), sNums.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        //if max == 0 -> all == 0
        //because '0 <= nums[i] <= 10^9'
        if (sNums[0] == "0") {
            return "0";
        }

        string ans;
        for (const string &num : sNums) {
            ans += num;
        }

        return ans;
    }
};
