class Solution {
public:
    int findTheLongestSubstring(string s) {

    std:;unordered_map<char, int> vowelBit = {
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3}, 
        {'u', 4}  
    };
    //  00000
    //->uoiea
    // 0 = even , 1 = odd

    std::unordered_map<int,int> firstBitmaskIndex;
    int bitmask = 0; //00000
    firstBitmaskIndex[0]=-1; // should not happen
    int maxLen = 0;

    //go over string
    for(int i=0;i<s.size();i++){
        char curr=s[i];

        //check for vowel
        //if found, swap even/odd state
        if(vowelBit.contains(s[i])){
            int maskIndex = vowelBit[s[i]];

            //push 1 onto the chars mask index
            //then perform XOR -> toggles state
            bitmask ^= (1 << maskIndex);
        }

        //check if this mask state was seen
        if(firstBitmaskIndex.contains(bitmask)){
            maxLen = std::max(maxLen,i-firstBitmaskIndex[bitmask]);
        }
        else{
            firstBitmaskIndex[bitmask] = i;
        }
    }
    return maxLen;

    }
};
