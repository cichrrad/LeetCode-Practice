/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> numSet;
        numSet.reserve(nums.size());
        
        for (auto &el : nums){
            numSet.insert(el);
        }
        
        int c = 0;
        bool running = false;
        ListNode* curr = head;
        //n*logk (n == sizeof linked list, k == sizeof nums)
        while(curr->next != nullptr){
            int cVal = curr->val;
            int nxtVal = (curr->next)->val;

            if(numSet.contains(cVal)){
                
                if(numSet.contains(nxtVal)){
                    if(running){
                        //nothing
                    }
                    else{
                        running = true;
                        c++;
                    }
                }
                else{
                    if(running){
                        running=false;
                    }
                    else{
                        c++;
                    }
                }
            }
            
            curr = curr->next;
            
        }
        
        if(!running && numSet.contains(curr->val)){
            c++;
        }
        return c;
    }
};
