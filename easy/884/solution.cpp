class Solution {
public:

    std::vector<std::string> slice(std::string s){
        std::vector<std::string> slices;
        std::istringstream iss(s);
        std::string word;
        while(std::getline(iss,word,' ')){
            slices.push_back(word);
        }
        return slices;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        std::vector<std::string> ans;
        auto wrds1 = slice(s1);
        auto wrds2 = slice(s2);

        //very small size (<= 200 chars)
        //-> brute force, we cookin
        std::map<std::string,int> word_counter;
        for(int i = 0 ; i<wrds1.size();i++){
            if(word_counter.contains(wrds1[i])){
                word_counter[wrds1[i]]++;
            }
            else{
                word_counter[wrds1[i]]=1;
            }
        }
        
        for(int i = 0 ; i<wrds2.size();i++){
            if(word_counter.contains(wrds2[i])){
                word_counter[wrds2[i]]++;
            }
            else{
                word_counter[wrds2[i]]=1;
            }
        }

        for(auto word:word_counter){
            if (word.second==1){
                ans.push_back(word.first);
            }
        }
        return ans;
    }
};
