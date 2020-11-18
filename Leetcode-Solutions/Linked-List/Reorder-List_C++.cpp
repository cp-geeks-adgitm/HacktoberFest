static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*>q;
        while(head!=NULL){
            q.push_back(head);
            head = head->next;
        }
        while(!q.empty()){
            if(q.size()<=2) break;
            ListNode * front = q.front();
            ListNode * back = q.back();
            q.pop_front();
            q.pop_back();
            q.back()->next=NULL;
            ListNode * hm = front->next;
            front->next = back;
            back->next = hm;
        }
    }
};