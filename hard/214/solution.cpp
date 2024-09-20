//sadly, too slow, but very intuitive


class Solution {
public:

    bool isPal(int l,int r,const std::string &s){
        for(int i=l,j=r; i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }

        return true;
    }

    string shortestPalindrome(string s) {

        //find the largest palindrome of the original s
        //pre-pend whats missing
        int r = s.size()-1;
        std::string pre="";
        while(r>=0){

            if(isPal(0,r,s)){
                break;
            }
            pre=pre+s[r];
            r--;
        }

        return (pre + s);
     }
};
