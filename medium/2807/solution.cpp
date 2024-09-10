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

int gcd(int a, int b) 
    { 
        int result = std::min(a, b); 
        while (result > 0) { 
            if (a % result == 0 && b % result == 0) { 
            break; 
            } 
            result--; 
        } 
        return result; 
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto _head = head;

        //edge case - size 1
        if (_head->next == nullptr){
            return _head;
        }
    
        while((_head->next)->next != nullptr){
        
        int _gcd = gcd(_head->val,_head->next->val);
        ListNode* newNode = new ListNode(_gcd,_head->next);
        _head->next = newNode;

        _head = newNode->next;

        }

        //process last pair
        int _gcd = gcd(_head->val,_head->next->val);
        ListNode* newNode = new ListNode(_gcd,_head->next);
        _head->next = newNode;

        return head;
    }
};
