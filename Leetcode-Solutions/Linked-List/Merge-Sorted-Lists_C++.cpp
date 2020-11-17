21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

Answer

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
    
    void append(ListNode** head_ref, int new_data){
        ListNode* new_node = new ListNode();
        
        new_node->val = new_data;
        new_node->next = NULL;
        
        ListNode *last = *head_ref;
        
        if(*head_ref == NULL){
            *head_ref = new_node;
            return;
        }
        
        //Else traverse till last
        while (last->next != NULL)  
            last = last->next;  
  
        /*Change the next of last node */
        last->next = new_node;  
        return;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* current1 = l1;
        ListNode* current2 = l2;
        
        ListNode* head = NULL;
        
        
        
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val <= l2->val){
                append(&head, l1->val);
                l1 = l1->next;
            }else{
                append(&head, l2->val);
                l2 = l2->next;
            }
                
                
            }
           else{
            if(l1 == NULL){
                    append(&head, l2->val);
                    l2 = l2->next;
                }else if(l2 == NULL){
                    append(&head, l1->val);
                    l1 = l1->next;
                }
        } 
        }
        return head;
    }
};