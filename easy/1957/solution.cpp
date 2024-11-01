//cursed
class Solution {
public:
    string makeFancyString(string s) {
        auto len = s.length();
        if(len<3){
            return s;
        }

        std::string ans="";
        unsigned int index=0;
        while(index+2<len){
            if(s[index]==s[index+1] && s[index+1]==s[index+2]){
                index++;
                continue;
            }
            ans+=s[index];
            index++;
        }
        //handle last 2
        ans+=s[len-2];
        ans+=s[len-1];
        return ans;
    }
};
