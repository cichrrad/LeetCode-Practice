class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //naive (slow) way - just sort as strings
        //O(nlogn) due to sorting
        //space O(n) due to additional vector

        std::vector<std::string> temp;
        for(int i = 1;i<n+1;i++){
            temp.push_back(to_string(i));
        }
        std::sort(temp.begin(),temp.end());

        std::vector<int> ans;
        for (int i = 0 ; i < temp.size();i++){
            ans.push_back(std::stoi(temp[i]));
        }
        return ans;
    }
};
