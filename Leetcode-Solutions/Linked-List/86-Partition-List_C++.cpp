class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* first=NULL,*second=NULL,*ptr=head,*ans=NULL,*ans1=NULL;
        while(ptr!=NULL)
        {
            if(ptr->val<x)
            {
                if(first==NULL)
                {
                    first=ptr;
                    ans=first;
                }
                else
                {
                    first->next=ptr;
                    first=first->next;
                }
            }
            else
            {
                if(second==NULL)
                {
                    second=ptr;
                    ans1=second;
                }
                else
                {
                    second->next=ptr;
                    second=second->next;
                }
            }
            ptr=ptr->next;
        }
        if(first!=NULL)
        first->next=ans1;
        else
            ans=ans1;
        if(second!=NULL)
        second->next=NULL;
        return ans;
    }
};
