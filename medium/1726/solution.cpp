class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

    //compute occurences of all pairs multiplications
    unordered_map<long long, int> products;
    int count=0;
    for(int i=0;i<nums.size()-1;i++){

        for(int j=i+1; j< nums.size();j++){

        long long idx = (long long)(nums[i]*nums[j]);
        count += products[idx];
        products[idx]++;
 
        }
    }
        
    // * 8 because for (a,b,c,d) we can do 8 tuples
    //abcd,bacd,abdc,badc,cdab,dcab,cdba,dcba
    return count*8; 
    }
};
