class Solution {
public:

    int findTheWinner(int n, int k) {
         //Jaderka for the win -- Josephus recurrence
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + k) % i;
        }
        return res + 1; // +1 cuz 1-indexed
    }
};
