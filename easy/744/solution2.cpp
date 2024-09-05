
/*
NOTE:
    Binary search solution
    The complexity of the 1st solution is 
    highly dependant on the relationship
    between the target and the letters

    Binary search solution should offer 
    stable performance O(log(n)), but comes
    with predicates (the set being ordered), which luckily
    are met, so we can use it

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size()-1;
        
        if(letters[l] > target || target >= letters[r])
            return letters[0];  
    
        char ans;  
        while(l <= r)
        {
            int mid=(l+r)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};