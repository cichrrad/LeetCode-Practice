
/*
NOTES:
    Very simple once you realize you can
    leverage the non-descending nature of
    the set -> removes the need for tracking
    'min' variable and allows for breaking
    as soon as first solution is found
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto &l : letters){
            if (l>target){
                return l;
            }
        }
        return (letters[0]);
    
    }
};


