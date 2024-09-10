class Solution {
public:
    int commonFactors(int a, int b) {

        int ans = 0;
        
        int smaller = std::min(a,b);
        int i = 1;
        while(i<=(smaller)){
            ans = (a%i == 0 && b%i==0 ) ? ans+1 : ans;
            i++;
        }
        return ans;
    }
};
