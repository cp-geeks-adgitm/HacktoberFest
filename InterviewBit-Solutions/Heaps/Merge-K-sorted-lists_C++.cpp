/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct comp
{
    bool operator()(ListNode* const& a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if(A.size()==0)
        return NULL;
    priority_queue<ListNode*, vector<ListNode*>,comp> q;
    ListNode* ans = new ListNode(0);

    ListNode* temp=ans;
    for(auto i=0;i<A.size();i++)
    {
        if(A[i]!=NULL)
            q.push(A[i]);
    }
    while(!q.empty())
    {
        
            temp->next=q.top();
            temp=temp->next;
            q.pop();
            if(temp->next!=NULL)
            {
                q.push(temp->next);
            }

        
    }
    return ans->next;

}
