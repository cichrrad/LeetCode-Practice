#include <iostream>
#include <vector>
#include <sstream>



class Solution {
public:

    vector<int> slice(string v) {
        std::vector<int> slices;
        std::stringstream ss(v);
        std::string slice;

        while (getline(ss, slice, '.')) {
            slices.push_back(stoi(slice));
        }
        
        return slices;
    }


    int compareVersion(string version1, string version2) {
        
        //slice the strings up
        std::vector<int> v1Slices = slice(version1);
        std::vector<int> v2Slices = slice(version2);

        int _max = max(v1Slices.size(), v2Slices.size());
        //pad to the larger one
        v1Slices.resize(_max, 0);
        v2Slices.resize(_max, 0);

        for (int i = 0; i < _max; i++) {
        
            if (v1Slices[i] < v2Slices[i]) {
                return -1;
            } 
            else if (v1Slices[i] > v2Slices[i]) {
                return 1;
            }
        }

        return 0;
    }

};

