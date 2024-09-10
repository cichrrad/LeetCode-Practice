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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head)
        {
            return nullptr;
        }

        ListNode *current = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while(even != nullptr && even->next != nullptr){
            current->next = even->next;
            current = current->next;
            even->next = current->next;
            even = even->next;
        }
        current->next = evenHead;
        return head;
    }
};
