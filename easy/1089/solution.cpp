class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        //create a vector of 0's
        vector<int> v(n,0);
            
        for(int i=0, k=0 ; k<n ; i++){

            if(!arr[i]){
                k+=2;
            }
            else{
                v[k]=arr[i];
                k++;
            }
        }
        //cpy back
        arr = v;
    }
};
