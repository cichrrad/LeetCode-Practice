class Solution {
public:
    string shortestPalindrome(string s) {

        //Using KMP (only way to get decent complexity, but less intuitive)
        std::string kmpString = s + '#' + std::string(s.rbegin(),s.rend());

        //prefix vector
        std::vector<int> pfV(kmpString.length(),0);
        int i = 1;
        int j = 0;
        
        while(i<kmpString.length()){
            if(kmpString[i] == kmpString[j]){
                j++;
                pfV[i]=j;
                i++;
                continue;
            }

            if(j){
                j = pfV[j-1];
                continue;
            }

            pfV[i]=0;
            i++;

        }

        int count = pfV.back();
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }
};
