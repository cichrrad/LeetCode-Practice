//naive:
//  brute force
//  works but takes too much time

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {

        unsigned int size = arr1.size();
        unsigned int max = 0;

        for(int i = 0 ; i < size; i++){
            for(int j = 0; j<size;j++){
                unsigned int exp = std::abs(arr1[i] - arr1[j])+std::abs(arr2[i] - arr2[j])+ std::abs(i-j);
                max = exp > max ? exp:max;

            }
        }
        return max;        
    }
};
