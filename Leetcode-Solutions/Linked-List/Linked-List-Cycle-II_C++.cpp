class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(head->next==NULL) return NULL;
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) break;
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};