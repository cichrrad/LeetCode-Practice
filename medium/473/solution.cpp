class Solution {
public:

    bool dfs(int idx, vector<int>& sticks, vector<int>& sides, int target) {

        // break case -- we placed all sticks
        if (idx == sticks.size()){
            //check for sum eq
            return(   sides[0] == target 
                   && sides[1] == target
                   && sides[2] == target
                   && sides[3] == target);
        }


        unordered_set<int> tried; // to avoid repetitions
        // due to symmetry
        
        int curr = sticks[idx];
        // try to place curr somewhere
        for (int i = 0; i < 4 ; i++){
            // if sides[i] + curr > target --> skip this branch
            if (sides[i] + curr > target){
                continue;
            }

            // if this was already tried (but in different order)
            if(tried.count(sides[i])){
                continue;
            }

            tried.insert(sides[i]);

            //try to place curr to side [i]
            sides[i] += curr;

            //progress with this branch and propagate true up
            // if this is the one
            if(dfs(idx + 1, sticks, sides, target)){
                return true;
            }
            // if the path above did not pan out
            sides[i] -= curr;
            if (sides[i] == 0) break;  // don’t try other empty sides
        }
        // no solution found :(
         return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {

    int max_stick = -1;
    int sum = 0;
    for (auto &el : matchsticks){   
        sum+= el;
        max_stick=max(max_stick,el);
    }

    // early bails
    if (sum % 4 != 0){
        return false;
    }
        
    if (max_stick > sum/4){
        return false;
    }

    // sort descending, so we prune earlier
    sort(matchsticks.begin(),matchsticks.end(),std::greater<int>());
    vector<int> sides(4,0);
    
    return dfs(0, matchsticks, sides, sum/4);
            
    }
};
