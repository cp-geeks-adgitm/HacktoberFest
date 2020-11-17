234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* mid = NULL;
        
        while(second!= NULL && second->next != NULL){
            first = first->next;
            second = second->next->next;
        }
        
        if(second != NULL) mid = first->next;
        else mid = first;
        
        ListNode* next =NULL;
        ListNode* prev = NULL;
        while(mid){
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        
        while(prev){
            if(head->val != prev->val) return false;
            head = head->next;
            prev= prev->next;
        }
        return true;
    }
};