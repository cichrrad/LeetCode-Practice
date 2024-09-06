
/*
 * Note:
 * Could very well be optimized in terms of memory and such
 * using actual bit-shifts and all that fancy stuff
 * but would work still basically the same way
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        
    std::string binaryStr = "";
    //base 10 -> 2 conversion
    while (n > 0) {
        binaryStr = (n % 2 == 0 ? "0" : "1") + binaryStr;

        //most likely worth it ?
        if(binaryStr.size() > 1){
            if(binaryStr[0] == binaryStr[1]){
                return false;
            }
        }
        // Shift the number right
        n /= 2;

    }
    //if we did not break during the conversion
    //=> we cooking
    return true;
    }
};
