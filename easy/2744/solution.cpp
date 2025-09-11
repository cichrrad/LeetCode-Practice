class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,string> pairs;

        int c = 0;
        for(auto &w: words){
            auto wRev = w;
            reverse(wRev.begin(),wRev.end());
            if(pairs.contains(wRev)){
                c++;
            }
            pairs[w] = wRev;
            // cout << w << " : " << wRev << "\n";
        }
        return c;
    }
};
