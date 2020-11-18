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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL or head->next==NULL){
            head=NULL;
            return head;
        }
        int size=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(size==n){
            return head->next;
        }
        
        
        ListNode*last=head;
        while(n--){
            if(last->next!=NULL){
               last=last->next; 
            }
        }
         ListNode*pre=head;
        while(last->next!=NULL){
            if(pre->next!=NULL){
                pre=pre->next;                
            }

            last=last->next;
        }
        
        pre->next=pre->next->next;
        
        return head;
    }
};
