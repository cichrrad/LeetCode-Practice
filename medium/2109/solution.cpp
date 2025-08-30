
#include <numeric>
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        std::string ret(s.size() + spaces.size(), ' ');
        
         size_t out = 0;     // write cursor in ret
        size_t prev = 0;    // left side

        for (int idx : spaces) {
            // copy s[prev..idx-1] into ret
            for (size_t i = prev; i < static_cast<size_t>(idx); ++i) {
                ret[out++] = s[i];
            }
            // skip the ' ' char
            ret[out++] = ' ';
            prev = idx; // next chunk starts at idx
        }

        // last chunk (last spaces element)
        for (size_t i = prev; i < s.size(); ++i) {
            ret[out++] = s[i];
        }
        return ret;
    }
};
