//mapa hash,puta madre
class Solution {
public:

    void slice(std::string s,std::map<std::string,int> &m){

        std::istringstream iss(s);
        std::string word;
        while(std::getline(iss,word,' ')){
            if(m.contains(word)){
                m[word]++;
            }
            else{
                m[word]=1;
            }
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        std::vector<std::string> ans;
        std::map<std::string,int> word_counter;
        slice(s1,word_counter);
        slice(s2,word_counter);

        for(auto word:word_counter){
            if (word.second==1){
                ans.push_back(word.first);
            }
        }
        return ans;
    }
};
