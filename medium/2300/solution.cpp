class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        // naive O(n*m) is too slow
        // idea -- for each spell[i], calculate
        // min str of potion to >= success
        // --> potion[j] must be >= (success/spell[i])

        // sort potions to leverage this
        // --> O(m*log(m) + n*log(m)) (sorting + finding lower_bounds)
        //I will mutate this, you cant stop me
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> pairs(spells.size());

        for (int i = 0; i < spells.size(); i++) {
            //calculate min strenght of potion
            long long minPotion = (success + spells[i] - 1) / spells[i];
            // find first element to be >= minPotion
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            // calculate # of elementes from it till end of potions
            pairs[i] = m - (it - potions.begin());
        }
        return pairs;
    }
};

