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
    ListNode* sortList(ListNode* head) {
        
        //naive -> extract,sort,insert in order
        //O(n*logn)
        //Space complexity: n
        
        std::vector<int> extracted_list;
        auto curr = head;
        while(curr!=nullptr){
            extracted_list.push_back(curr->val);
            curr = curr->next;
        }

        std::sort(extracted_list.begin(),extracted_list.end());
        curr = head;
        int c=0;
        while(curr != nullptr){
            curr->val = extracted_list[c];
            c++;
            curr=curr->next; 
        }

        return head;
    }
};
