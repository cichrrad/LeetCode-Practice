class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        auto n = s1.length(); // == s2.length()
        short diffs = 0;
        char s1_a,s2_a,s1_b,s2_b;
        for(int i = 0 ; i < n ; i++){
            
            if(s1[i]!=s2[i]){
                
                diffs++;
                if(diffs <=2){
                    
                    if (diffs == 1){
                        s1_a = s1[i];
                        s2_a = s2[i];
                    }
                    //diffs == 2
                    else {
                        s1_b = s1[i];
                        s2_b = s2[i];  
                    }
                    
                }
                else{
                    return false;
                }
            }
        }
    
        if (diffs == 0){
            return true;
        }

        if (diffs == 1){
            return false;
        }
        
        if(s1_a == s2_b && s1_b == s2_a){
            return true;
        }
        return false;
        
    }
};
