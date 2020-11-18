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
    ListNode* reverseList(ListNode* head) {
        // this one is iterative
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=pre;
            pre=curr;curr=temp;
            
        }
        
        return pre;
        
// //         this is recursive
        
//         if(head==NULL or head->next==NULL){
//             return head;
//         }
        
//         ListNode* newhead=reverseList(head->next);
        
//         ListNode* curr= head;
//         curr->next->next=curr;
//         curr->next=NULL;
//         return newhead;
    }
};
