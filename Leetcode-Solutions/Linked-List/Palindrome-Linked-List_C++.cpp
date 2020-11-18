class Solution {
public:
    bool isPalindrome(ListNode* head) {
	ListNode* slowp = head;
    ListNode* fastp = head;
    ListNode* revp = NULL;
	while (fastp && fastp->next){
		fastp = fastp->next->next;
		ListNode* tmp = slowp->next;
		slowp->next = revp;
		revp = slowp;
		slowp = tmp;
	}
	if (fastp) slowp = slowp->next;
	while (slowp && revp){
		if (slowp->val != revp->val) return false;
		slowp = slowp->next;
		revp = revp->next;
	}
	return true;
}
};