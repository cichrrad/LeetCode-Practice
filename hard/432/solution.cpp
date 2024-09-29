//easy until you realize O(1) for max and min are PAIN

class AllOne {
public:
        std::unordered_map<std::string,int> strCounts;
        std::string minKey = "";
        std::string maxKey = "";
        int maxKeyCount=-1;
        unsigned int minKeyCount=-1; 
    AllOne() {
        //constructor
    }
    
    void inc(string key) {
        strCounts[key]++;
        
        if(strCounts[key]>= maxKeyCount){
           maxKeyCount = strCounts[key];
           maxKey = key; 
        }
        if(strCounts[key] <= minKeyCount){
           minKeyCount = strCounts[key];
           minKey = key; 
        }
    }
    
    void dec(string key) {
        if(strCounts[key]==1){
            strCounts.erase(key);
            return;
        }
        strCounts[key]--;
        if(strCounts[key] <= minKeyCount){
           minKeyCount = strCounts[key];
           minKey = key; 
        }
        if(strCounts[key]>=maxKeyCount){
           maxKeyCount = strCounts[key];
           maxKey = key; 
        }
    }
    
    string getMaxKey() {
        //screw O(1), we ballin O(n)
        int max = -1;
        std::string ans="";
        for(auto const& [key,count]:strCounts){
            if(count >= max){
                max = count;
                ans = key;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        //screw O(1), we ballin O(n)
        unsigned int min = -1; //cursed overflow
        std::string ans="";
        for(auto const& [key,count]:strCounts){
            if(count <= min){
                min = count;
                ans = key;
            }
        }
        return ans;    
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
