class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=0;
        ListNode* ptr=head,*temp=head;
        while(ptr!=NULL)
        {
            len++;
            ptr=ptr->next;
        }
        k%=len;
        if(k==0)
            return head;
        k=len-k;
        ptr=head;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            k--;
            if(k==0)
            {
                temp=ptr->next;
                ptr->next=NULL;
                ptr=temp;
            }
            else
            ptr=ptr->next;
        }
        ptr->next=head;
        // head=temp;
        return temp;
    }
};
