//Contributed by: Rishabh Jain 

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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid=head;
        ListNode* fast=head;
        while(fast->next!=NULL ){
            mid=mid->next;
            if(fast->next->next!=NULL){
                fast=fast->next->next;
            }
            else{
                fast=fast->next;
            }
            
        }
        return mid;
    }
};
