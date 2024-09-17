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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //naive way -> slot in list2
        //memory leaks? nah

        int c=0;
        //[l1 nodes A][l2][l1 nodes B]
        //find [l1 nodes A] end
        auto l1Curr=list1;
        while(c<a-1){
            l1Curr=l1Curr->next;
            c++;
        }

        //hook l2
        auto temp = l1Curr->next;
        l1Curr->next = list2;
        while(c<b){
            temp=temp->next;
            c++;
        }

        //find [l1 nodes B] beginning
        auto l2Curr = list2;
        while(l2Curr->next != nullptr){
            l2Curr = l2Curr->next;
        }
        l2Curr->next = temp;

        return list1;
    }
};
