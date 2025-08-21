class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first_seen(26,-1);
        
        for(int i=0;i<s.length();i++){
            char &c =s[i];
            //if second occurence of [c]
            if(first_seen[c-'a']!=-1){
                //verify with distance
                if(distance[c-'a'] != i-first_seen[c-'a']-1){
                    return false;
                }
            }
            // note index of first occurence of [c]
            else{
                first_seen[c-'a'] = i;
            }
        }
        return true;
        
    }
};
