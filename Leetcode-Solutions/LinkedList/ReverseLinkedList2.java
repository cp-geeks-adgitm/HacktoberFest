package LinkedList;

public class ReverseMtoN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	  public ListNode reverseBetween(ListNode head, int m, int n) {
	        if(head==null || head.next==null || m==n) return head;
	        
	        ListNode dummy=new ListNode(-1);
	        dummy.next=head;
	        int count=1;
	        ListNode curr=head;
	        ListNode prev=dummy;
	        while(curr!=null && count <m){
	           
	               prev=curr;
	               curr=curr.next;
	               count++;
	          
	        }
	        ListNode a=curr;
	        ListNode b=curr.next;
	        ListNode c=b.next;
	        
	        while(count<n){
	            b.next=a;
	            a=b;
	            b=c;
	            if(c!=null)
	            c=c.next;
	            
	            count++;
	        }
	        
	        prev.next=a;
	        curr.next=b;
	        
	        return dummy.next;
	    }
}
