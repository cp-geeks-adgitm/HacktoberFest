package LinkedList;

public class DeleteDuplicates {

	 public ListNode deleteDuplicates(ListNode head) {
	        if(head==null || head.next==null){
	            return head;
	        }
	        ListNode dummy=new ListNode(-1);
	        dummy.next=head;
	        
	        ListNode pprev=dummy;
	        ListNode prev=head;
	        ListNode curr=head.next;
	        
	        while(prev!=null && curr!=null){
	            
	            if(curr.val==prev.val){
	                ListNode temp=curr.next;
	                while(temp!=null && temp.val==curr.val){   
	                     temp=temp.next;
	                }
	                pprev.next=temp;
	                prev=temp;
	                if(temp!=null){
	                    curr=temp.next;
	                }
	                
	            }else{
	                pprev=prev;
	                prev=curr;
	                curr=curr.next;
	                
	            }
	        }
	        return dummy.next;
	    }

}
