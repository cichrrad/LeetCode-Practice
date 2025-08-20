class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
    
        unsigned int n = s.length();

        //early bail
        if (s[n-1]=='1'){
            return false;
        }
        
        // BFS queue
        queue<unsigned int> q;
        q.push(0); // constraint -- s[0] == '0'

        //furthest reachable index (if == s.lenght -1 --> bail and TRUE)
        unsigned int rmost = 0; 
        
        // mask to check off seen indexes
        vector<char> visited(n,false); 

        while(!q.empty()){
            //get new 'start' index
            auto curr = q.front();
            q.pop();

            //calculate window at offset from curr
            auto l = max(curr+minJump,rmost+1);
            auto r = min(curr+maxJump,n-1);

            // scan the window
            for (auto i = l ; i<=r; i++){
                if (s[i]=='0' && !visited[i]){

                    // end is reachable -- TRUE
                    if (i == n-1){
                        return true;
                    }
                    visited[i]=true;
                    q.push(i);
                }
            }
            rmost = max(rmost,r);
            
        }
        return false;
    }
};
