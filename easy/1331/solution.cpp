class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        m.reserve(arr.size());
        
        vector<int> sorted = arr;
        //O(nlog(n))
        sort(sorted.begin(),sorted.end());

        
        // map values to ranks
        //O(n)
        int idx = 1;
        for(int i = 0; i<arr.size();i++){
            if(!(m.contains(sorted[i]))){
                m[sorted[i]]=idx++;
            }
        }

        //O(n)
        vector<int> ret(arr.size());
        for(int i = 0; i < ret.size();i++){
            ret[i] = m[arr[i]];
        }


    //~ O(2n + nlog(n)) --> O(nlog(n))
    return ret;
    
    }
};
