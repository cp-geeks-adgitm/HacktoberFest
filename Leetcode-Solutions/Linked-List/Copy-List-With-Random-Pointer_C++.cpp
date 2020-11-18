static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>m;
        Node * temp;
        Node * newNode = new Node(head->val);
        temp = newNode;
        m[head] = newNode;
        Node * hd = temp;
        head = head->next;
        while(head!=NULL){
            Node* newNode = new Node(head->val);
            temp->next = newNode;
            m[head] = newNode;
            head=head->next;
            temp=temp->next;
        }
        for(auto i : m){
            if(i.first->random==NULL) i.second->random = NULL;
            else{
                i.second->random = m[i.first->random];
            }
        }
        return hd;
    }
};