class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        // look at 2 "adjacent" nodes
        while (curr && curr->next) {
            // if they are same, make the -> next node further away and skip this one
            if (curr->val == curr->next->val) {
                
                curr->next = curr->next->next;
            // if not, move as usual
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

