
// less cringe solution:

/*
    Best way to approach this is to
    try and get rid of abs value
    -> this helps us identify
    8 possible patterns of signs
    that can happen, because:
        
        > |arr1[i] - arr1[j]| = 'x - y' or '-x + y' (based on values)
        > |arr2[i] - arr2[j]| = 'x - y' or '-x + y' (based on values)
        > |i - j| = 'i - j' or '-i + j' (based on values)
    
    now if we combine these to show
    all scenarios, we end up with:
        > (arr1[i] - arr1[j]) + (arr2[i] - arr2[j]) + (i - j) 
            ===> (arr1[i]+arr2[i] + i) - (arr1[j] + arr2[j] + j)
            ===> we get max value, when first bracket is max and second min

        > (-arr1[i] + arr1[j]) + (-arr2[i] + arr2[j]) + (-i + j)
            ===> (arr1[j]+arr2[j]+j) - (arr1[i]+arr2[i]+i)
            ===> max value, when first is max and second min

        //and so on for other 6 patterns

    We can utilize this in our solution,
    where we can simplify our problem by it and
    look for maximal differnce instead.

    Furthermore, sign patterns are symetric
    -> checking 4 is enough.

*/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;
        int max3 = INT_MIN, min3 = INT_MAX;
        int max4 = INT_MIN, min4 = INT_MAX;

        for (int i = 0; i < arr1.size(); ++i) {
            // compute for the 4 patterns (other 4 are symmetric)
            int val1 = arr1[i] + arr2[i] + i;
            int val2 = arr1[i] + arr2[i] - i;
            int val3 = arr1[i] - arr2[i] + i;
            int val4 = arr1[i] - arr2[i] - i;

            max1 = max(max1, val1);
            min1 = min(min1, val1);
            max2 = max(max2, val2);
            min2 = min(min2, val2);
            max3 = max(max3, val3);
            min3 = min(min3, val3);
            max4 = max(max4, val4);
            min4 = min(min4, val4);
        }

        // result is max diff
        return max({
            max1 - min1,
            max2 - min2,
            max3 - min3,
            max4 - min4
        });
    }
};

