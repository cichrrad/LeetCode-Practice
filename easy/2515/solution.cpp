class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {


    // perhaps too 'general' and made to be intuitive
    // could get away with single scan noting indices where words[i] == target
    // then for each finding min(going left of startIndex, going right of startIndex)
    // and min of those...

    // technically same complexity O(N), but shown approach would be slower in practice
        
        queue<string> q;
        q.push(words[startIndex]);
        q.push(words[startIndex]);
        int offset = 0;
        int steps = 0;
        int n = words.size();
        
        while(steps < n){
            if(q.front() == target || q.back()==target){
                return steps;
            }

            offset++;
            q.pop();
            q.pop();
            q.push(words[(startIndex + offset) % n]);
            q.push(words[(startIndex - offset + n) % n]);
            steps++;
            
        }
        return -1;
        
    }
};
